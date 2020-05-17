<?php

/**
 * @file
 * Default template for type ahead search form.
 */
?>

<div class="search-box-block">
  <div class="search-box-block--wrapper">
    <div>
      <div class="search-filters--search-box">
        <label for="typeahead"><?php print t('Search for an answer'); ?></label>
        <?php print drupal_render_children($form); ?>
      </div>

      <div class="search-filters">
        <div class="search-filters--type">
          <?php print loop_search_db_facet_link(t('All'), 'type', NULL, ['attributes' => ['class' => ['search-filters--label']]]); ?>
          <?php print loop_search_db_facet_link(t('Documents'), 'type', 'loop_documents_document', ['attributes' => ['class' => ['search-filters--label']]]); ?>
          <?php print loop_search_db_facet_link(t('Posts'), 'type', 'post', ['attributes' => ['class' => ['search-filters--label']]]); ?>
        </div>

        <?php if (isset($form['#facets']['field_subject:name'])): ?>
          <span class="search-filters--subject-wrapper" data-ng-click="toggleFilter()">
            <span class="search-filters--subject-wrapper-label">
              <?php $active_filters = loop_search_db_get_active_filters('field_subject'); ?>
              <?php if (count($active_filters) > 0): ?>
                <span><?php print format_plural(count($active_filters), '1 selected subject', '@count selected subjects'); ?></span>
              <?php else: ?>
                <span><?php print t('Filter on subjects') ?></span>
              <?php endif ?>
              <img class="search-filters--icon-dropdown" src="/profiles/loopdk/themes/loop/images/nav-arrow-down-icon.png">
            </span>
          </span>

          <div class="search-filters--subjects-wrapper">
            <div class="search-filters--subjects">
              <div class="search-filters--arrow"><div class="search-filters--arrow-inner"></div></div>
              <div class="search-filters--subjects-inner">
                <?php foreach ($form['#facets']['field_subject:name'] as $facet): ?>
                  <div class="search-filters--subjects-item" data-ng-repeat="(key, item) in filters['taxonomy']['field_subject'].items">
                    <span class="search-filters--subjects-item-inner">
                      <input id="{{ key }}" type="checkbox" data-ng-model="query.filters['taxonomy']['field_subject'][key]" data-ng-click="filterNewSelection()">
                      <label for="{{ key }}"><?php print $facet['filter']; ?></label>
                    </span>
                  </div>
                <?php endforeach ?>
              </div>
              <span data-ng-click="toggleFilter()" class="search-filters--action"><?php print t('Filter') ?></span>
            </div>
          </div>
        <?php endif ?>
      </div>

<?php if(0===1): ?>
      <div class="search-filters--sort">
        <div class="search-filters--sort-text"><?php print t('Sort results') ?></div>
        <div class="search-filters--sort-labels">
          <span class="search-filters--label" data-ng-class="{'is-active': sortActive==='default'}" data-ng-click="sortOrder('default')"><?php print t('Best match'); ?></span>
          <span class="search-filters--label" data-ng-class="{'is-active': sortActive==='desc'}" data-ng-click="sortOrder('desc')"><?php print t('Newest'); ?></span>
          <span class="search-filters--label" data-ng-class="{'is-active': sortActive==='asc'}" data-ng-click="sortOrder('asc')"><?php print t('Oldest'); ?></span>
          <span class="search-filters--label" data-ng-class="{'is-active': sortActive==='alpha'}" data-ng-click="sortOrder('alpha')"><?php print t('Alphabetical'); ?></span>
        </div>
      </div>
<?php endif ?>

    </div>
  </div>
</div>




<pre><?php
//var_export(($form['#facets']));

?></pre>
