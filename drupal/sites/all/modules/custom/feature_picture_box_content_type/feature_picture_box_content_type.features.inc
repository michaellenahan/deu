<?php
/**
 * @file
 * feature_picture_box_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function feature_picture_box_content_type_node_info() {
  $items = array(
    'picture_box' => array(
      'name' => t('Picture box'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
