<?php

/**
 * Admin settings form for yipit
 * callback for admin/config/services/yipit
 */
function yipit_admin_settings_form(){

	$form = array();

	$form['yipit_key'] = array(
		'#type' => 'textfield',
		'#title' => t('Yipit Api Key'),
		'#default_value' => variable_get('yipit_key',''),
	);

	$form['deals'] = array(
		'#type' => 'fieldset',
		'#title' => t('Deals'),
		'#collapsible' => true,
		'#collapsed' => false,
	);

	$form['deals']['yipit_deals_url'] = array(
		'#type' => 'textfield',
		'#title' => t('Yipit deals url'),
		'#description' => t('Deals url that fetch the data from yipit i.e. - http://api.yipit.com/v1/deals'),
		'#default_value' => variable_get('yipit_deals_url',''),
	);

	$form['deals']['yipit_deals_division'] = array(
		'#type' => 'textfield',
		'#title' => t('Division'),
		'#description' => t('Deals division like new-york,atlanta etc..'),
		'#default_value' => variable_get('yipit_deals_division',''),
	);

	$form['deals']['yipit_deals_source'] = array(
		'#type' => 'textfield',
		'#title' => t('Source'),
		'#description' => t('Deals sources like groupon, scoutmob etc.. '),
		'#default_value' => variable_get('yipit_deals_source',''),
	);

	$form['deals']['yipit_deals_tags'] = array(
		'#type' => 'textfield',
		'#title' => t('Tags'),
		'#description' => t('Deals filter by tags i.e. travel, restaurant etc.'),
		'#default_value' => variable_get('yipit_deals_tags',''),
	);

	$form['deals']['yipit_deals_limit'] = array(
		'#type' => 'textfield',
		'#title' => t('Limit'),
		'#description' => t('Deals Limit to fetch data per call'),
		'#default_value' => variable_get('yipit_deals_limit',''),
	);

	$form['deals']['yipit_deals_paid'] = array(
		'#type' => 'checkbox',
		'#title' => t('Filter by Paid ?'),
		'#description' => t('Filter Deals if paid or not'),
		'#default_value' => variable_get('yipit_deals_paid',''),
	);

	$form['deals']['yipit_deals_fetch_all'] = array(
		'#type' => 'checkbox',
		'#title' => t('Fetch all data?'),
		'#description' => t('fetch all data while we fetch data'),
		'#default_value' => variable_get('yipit_deals_fetch_all',''),
	);

	//return $form;
	return system_settings_form($form);
}
