<?php

/**
 * @file
 * Template for user taxonomy subscriptions.
 */
?>
<?php foreach ($fields as $field): ?>
  <div class="subscriptions--item">
    <?php print $field->content; ?>
  </div>
<?php endforeach ?>
