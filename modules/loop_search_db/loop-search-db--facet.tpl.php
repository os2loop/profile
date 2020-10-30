<?php

/**
 * @file
 * Template file for facet.
 */

  $key = $filter_name . '-' . $index;
  $name = 'f[]';
  $text = $facet['filter'];
  $value = urlencode($filter_name) . ':' . $text;
  $checked = $facet['active'] ?? FALSE;
  $class_name = 'search-filters--' . $facet_name . '-item';
?>

<div class="search-filters--facets-item <?php print $class_name; ?>">
  <span class="search-filters--facets-item-inner <?php print $class_name; ?>-inner">
    <input id="<?php print $key; ?>" type="checkbox" name="<?php print $name; ?>" <?php print $checked ? ' checked ' : ''; ?> value="<?php print htmlspecialchars($value) ?>"/>
    <label for="<?php print $key; ?>"><?php print $text; ?></label>
  </span>
  <?php if ($facet['children']): ?>
    <div class="search-filters--facets-children">
      <?php
        foreach ($facet['children'] as $index => $facet) {
          print theme('loop_search_db_facet', [
            'index' => $index,
            'facet' => $facet,
            'facet_name' => $facet_name,
            'filter_name' => $filter_name,
          ]);
        }
      ?>
    </div>
  <?php endif ?>
</div>
