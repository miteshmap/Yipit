<?php

/**
 * @file
 * adds a formatter for text fields that dispaly url as image tag
 *
 */

/**
 * Implements hook_field_formatter_info().
 */
function yipit_field_formatter_info() {
  return array(
    'yipit_formatter' => array( //Machine name of the formatter
      'label' => t('Yipit Image'),
      'field types' => array('text'),
      'settings'  => array( //Array of the settings we'll create
        'pic_class' => 'yipit-image', //give a default value for when the form is first loaded
      ),
    ),
  );
}


/**
 * Implements hook_field_formatter_settings_form().
 */
function yipit_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  //This gets the view_mode where our settings are stored
  $display = $instance['display'][$view_mode];
  //This gets the actual settings
  $settings = $display['settings'];
  //Initialize the element variable
  $element = array();

  $element['pic_class'] = array(
    '#type'           => 'textfield',                        // Use a textbox
    '#title'          => t('Image class'),                      // Widget label
    '#description'    => t('add multiple classes with space'),  // helper text
    '#default_value'  => $settings['pic_class'],               // Get the value if it's already been set
  );
  return $element;
}


/**
 * Implements hook_field_formatter_settings_summary().
 */
function yipit_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $summary = t('class(es) added to image tag - @pic_class', array(
    '@pic_class'     => $settings['pic_class'],
  )); // we use t() for translation and placeholders to guard against attacks
  return $summary;
}



/**
 * Implements hook_field_formatter_view().
 */
function yipit_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array(); // Initialize the var
  $settings = $display['settings']; // get the settings
	$class = $settings['pic_class']; // The Size setting selected in the settings form
  // Create the image - Note that I'm storing the images in our module but they could be anywhere
  foreach ($items as $delta => $item) {
    $image = '<img src="'. $item['value'] .'" class="'.$class.'">';// Getting the actual value
    $element[$delta]['#markup'] = $image; // Assign it to the #markup of the element
  }

  return $element;
}
