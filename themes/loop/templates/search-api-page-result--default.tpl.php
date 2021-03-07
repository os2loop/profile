<?php

/**
 * @file
 * Default theme implementation for displaying a single search result.
 *
 * This template renders a single search result and is collected into
 * search-api-page-results.tpl.php. This and the parent template are dependent
 * on one another, sharing the markup for definition lists.
 *
 * View mode is set in the Search page settings. If you select
 * "Themed as search results", then this template will be used for theming the
 * individual results. Any other view mode will bypass this template.
 *
 * Available variables:
 * - $index: The search index this search is based on.
 * - $url: URL of the result.
 * - $title: Title of the result.
 * - $snippet: A small preview of the result.
 * - $info: String of all the meta information ready for print. Applies
 *   only if the result is a node.
 * - $info_split: Contains same data as $info, split into a keyed array.
 * - $classes: CSS classes for this list element.
 *
 * Default keys within $info_split:
 * - $info_split['user']: Author of the entity, where an author exists.
 *   Depends on permission.
 * - $info_split['date']: Last update of the entity, if the 'updated'
 *   field exists. Short formatted.
 *
 * Since $info_split is keyed, a direct print of the item is possible.
 * This array applies where the search result is a node, so it is
 * recommended to check for its existence before printing.
 * Where the result is a node, the default keys of 'user' and 'date'
 * will always exist.
 *
 * To check for all available data within $info_split, use the code below.
 * @code
 *   <?php print '<pre>'. check_plain(print_r($info_split, 1)) .'</pre>'; ?>
 * @endcode
 *
 * @see template_preprocess_search_api_page_result()
 */
?>
<?php $url['options']['attributes']['class'] = 'search-result--link search-node-result--link';?>

<div class="search-node-result--item">
  <?php print $url ? l($title, $url['path'], $url['options'] + ['html' => TRUE]) : $title; ?>
  <div class="search-node-result--item-content">
    <div class="search-node-result--data-wrapper">
      <div class="search-node-result--meta-data-type is-<?php print $item->type; ?>">
        <?php print t($item->type); // phpcs:ignore ?>
      </div>
    </div>

    <?php if (isset($item->field_subject[LANGUAGE_NONE][0]['tid'])): ?>
      <?php $subject = taxonomy_term_load($item->field_subject[LANGUAGE_NONE][0]['tid']); ?>
      <div class="search-node-result--data-wrapper-subject"><?php print t('Subject'); ?>:
        <div class="search-node-result--subject" data-filter-update="<?php
print htmlspecialchars(json_encode(['field_subject', $subject->name]));
?>"><?php print $subject->name; ?></div>
      </div>
    <?php endif; ?>

    <div class="search-node-result--meta-data-date">
      <?php print format_date($item->created, 'custom', 'd. M Y'); ?>
    </div>
    <?php if ('post' === $item->type): ?>
      <div class="search-node-result--data-wrapper">
        <?php print l(format_plural($item->comment_count, '1 answer', '@count answers'), $url['path'], ['attributes' => ['class' => ['search-result--comments']]]); ?>
      </div>
    <?php endif ?>
  </div>
</div>
