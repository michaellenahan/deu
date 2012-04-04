<?php
/**
 * @file
 * Commerce Multicurrency rules integration.
 */

/**
 * Implements hook_rules_event_info().
 */
function commerce_multicurrency_rules_event_info() {
  $events = array();

  $events['commerce_multicurrency_user_currency_set'] = array(
    'label' => t('After the user currency has set'),
    'group' => t('Commerce Multicurrency'),
    'variables' => array(
      'currency_code' => array(
        'type' => 'text',
        'label' => t('The currency code to use'),
      ),
      'old_currency_code' => array(
        'type' => 'text',
        'label' => t('The currency code used before'),
      ),
    ),
    'access callback' => 'commerce_order_rules_access',
  );
  return $events;
}
