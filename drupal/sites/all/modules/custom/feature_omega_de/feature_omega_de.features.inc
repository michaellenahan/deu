<?php
/**
 * @file
 * feature_omega_de.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_omega_de_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_omega_de_node_info() {
  $items = array(
    'gallery' => array(
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('An image gallery.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'online_magazine' => array(
      'name' => t('Online magazine'),
      'base' => 'node_content',
      'description' => t('This is the swf file that the user has paid for. It is a protected piece of content, only available to signed-up users who have purchased it.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
