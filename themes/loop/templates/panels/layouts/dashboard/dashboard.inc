<?php

/**
 * @file
 * Implementation of hook_panels_layouts().
 */

$plugin = [
  'title' => t('Dashboard'),
  'category' => t('Loop custom'),
  'icon' => 'dashboard.png',
  'theme' => 'dashboard',
  'regions' => [
    'alpha' => t('Alpha'),
    'beta' => t('Beta'),
    'gamma' => t('Gamma'),
    'delta' => t('Delta'),
  ],
];
