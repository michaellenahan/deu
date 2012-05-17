<?php
/**
 * @file
 * feature_omega_de.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function feature_omega_de_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'delta_de_front';
  $context->description = '';
  $context->tag = 'theme';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'magazine' => 'magazine',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'delta_de_front',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('theme');
  $export['delta_de_front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'delta_de_gallery';
  $context->description = '';
  $context->tag = 'theme';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'gallery' => 'gallery',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'delta_de_gallery',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('theme');
  $export['delta_de_gallery'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'delta_de_online_magazine';
  $context->description = '';
  $context->tag = 'theme';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'online_magazine' => 'online_magazine',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'delta_de_online_magazine',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('theme');
  $export['delta_de_online_magazine'] = $context;

  return $export;
}
