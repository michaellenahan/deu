<?php
/**
 * @file
 * Defines default currency selection components and rules.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function commerce_multicurrency_default_rules_configuration() {
  $rules = array();

  // Ensure the commerce constants are set.
  drupal_load('module', 'commerce');

  $reaction_rule = rules_reaction_rule();
  $reaction_rule->label = t('Set the currency price');
  $reaction_rule->active = TRUE;
  $reaction_rule->weight = -9;

  foreach (commerce_currencies(TRUE) as $currency_code => $currency_info) {
    $field_name = 'commerce_price_' . strtolower($currency_code);
    $rule_name = 'commerce_multicurrency_use_' . strtolower($currency_code);
    $field_info = field_info_field($field_name);
    if (!$field_info) {
      $saved_rule = rules_config_load($rule_name);
      if ($saved_rule !== FALSE && ($saved_rule->status | ENTITY_IN_CODE)) {
        $saved_rule->delete();
      }
      continue;
    }
    $rule = rule(array(
      'commerce_line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('Line item'),
      ),
    ));

    // Version dependent parameters for commerce_line_item_unit_price_amount.
    $commerce_line_item_unit_price_amount_params = array(
      'commerce-line-item:select' => 'commerce-line-item',
      'amount:select' => 'commerce-line-item:commerce-product:' . $field_name . ':amount',
      'component_name' => 'base_price',
    );
    // Rounding introduced with this commit: http://drupalcode.org/project/commerce.git/commit/72c9efa8949c97e35b7afdda2352bed006b557e5
    if (defined('COMMERCE_ROUND_HALF_UP')) {
      $commerce_line_item_unit_price_amount_params['round_mode'] = COMMERCE_ROUND_HALF_UP;
    }

    $rule->label = t('Use the ' . $currency_code . ' price');
    $rule->active = TRUE;
    $rule
      ->condition('data_is', array(
        'data:select' => 'site:commerce-currency',
        'value' => $currency_code,
      ))
      ->condition('entity_has_field', array(
        'entity:select' => 'commerce-line-item',
        'field' => 'commerce_product',
      ))
      ->condition('entity_has_field', array(
        'entity:select' => 'commerce-line-item:commerce-product',
        'field' => $field_name,
      ))
      ->condition($empty_condition = rules_condition('data_is_empty', array(
        'data:select' => 'commerce-line-item:commerce-product:' . $field_name,
      )))
      ->action('commerce_line_item_unit_price_amount', $commerce_line_item_unit_price_amount_params)
      ->action('commerce_line_item_unit_price_currency_code', array(
        'commerce-line-item:select' => 'commerce-line-item',
        'currency_code:select' => 'commerce-line-item:commerce-product:' . $field_name . ':currency_code',
      ));

    $empty_condition->negate();

    $rules[$rule_name] = $rule;
    $reaction_rule->action('component_' . $rule_name, array(
      'commerce_line_item:select' => 'commerce-line-item',
    ));
  }

  $reaction_rule
    ->event('commerce_product_calculate_sell_price');
  $rules['commerce_multicurrency_set_currency_price'] = $reaction_rule;

  return $rules;
}
