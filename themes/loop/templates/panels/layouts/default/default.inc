<?php

/**
 * @file
 * Implementation of hook_panels_layouts().
 */

$plugin = [
  'title' => t('Default'),
  'category' => t('Loop custom'),
  'icon' => 'default.png',
  'theme' => 'default',
  'regions' => [
    'alpha' => t('Alpha'),
    'beta' => t('Beta'),
    'gamma' => t('Gamma'),
  ],
];
