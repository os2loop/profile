<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 */
?>
<?php
  // @TODO Use template suggestions to customize this.
  if ('loop_user_taxonomy_subscriptions' === $view->name && 'views_tree_plugin_style_tree' === get_class($view->style_plugin)):
?>
  <?php foreach ($fields as $field): ?>
    <div class="subscriptions--item">
      <?php print $field->content; ?></span>
    </div>
  <?php endforeach ?>
<?php else: ?>
  <?php include drupal_get_path('module', 'views') . '/theme/views-view-fields.tpl.php'; ?>
<?php endif ?>
