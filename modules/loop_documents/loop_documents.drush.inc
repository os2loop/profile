<?php

/**
 * @file
 * Drush commands for the loop_documents module.
 */

/**
 * Implements hook_drush_command().
 */
function loop_documents_drush_command() {
  $commands['loop-documents-reset-editor-configuration'] = array(
    'description' => 'Reset wysiyg editor configuration.',
    'examples' => array(
      'drush loop-documents:editor-reset' => 'Reset editor configuration.',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
  );

  return $commands;
}

/**
 * Reset editor configuration.
 */
function drush_loop_documents_reset_editor_configuration() {
  if (drush_confirm(dt('Are you sure you want to reset the editor configuration?'))) {
    loop_documents_reset_editor_configuration();
  }
}
