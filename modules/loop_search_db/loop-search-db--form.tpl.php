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

      <?php if (isset($form['#facets'])): ?>
        <div class="search-filters">
          <?php if (isset($form['#facets']['type'])): ?>
            <div class="search-filters--type">
              <?php
                // @TODO We should propably use some theme function for this, right?
              ?>
              <?php foreach ($form['#facets']['type'] as $index => $facet): ?>
                <?php $name = 'f[]'; ?>
                <?php $text = trim($facet['filter'], '"'); ?>
                <?php $value = $text ? urlencode('type') . ':' . $text : ''; ?>
                <?php $checked = $facet['active'] ?? FALSE; ?>

                <label class="search-filters--label <?php print $checked ? ' is-active' : ''; ?>"><?php print $facet['text'] ?? $facet['filter']; ?>
                  <input type="checkbox" name="<?php print $name; ?>" <?php print $checked ? ' checked ' : ''; ?> value="<?php print htmlspecialchars($value) ?>"/>
                </label>
              <?php endforeach ?>
            </div>
          <?php endif ?>

          <?php if (isset($form['#facets']['field_subject:name']) || isset($form['#facets']['field_keyword:name'])): ?>
            <span class="search-filters--facets-wrapper">
              <span class="search-filters--facets-wrapper-label">
                <?php $active_filters = loop_search_db_get_active_filters('field_subject') + loop_search_db_get_active_filters('field_keyword'); ?>
                <?php if (count($active_filters) > 0): ?>
                  <span><?php print format_plural(count($active_filters), '1 selected taxonomy term', '@count selected taxonomy terms'); ?></span>
                <?php else: ?>
                  <span><?php print t('Filter on taxonomy terms') ?></span>
                <?php endif ?>
                <img class="search-filters--icon-dropdown" src="/profiles/loopdk/themes/loop/images/nav-arrow-down-icon.png">
              </span>
            </span>

            <div class="search-filters--facets">
              <div class="search-filters--arrow"><div class="search-filters--arrow-inner"></div></div>
              <div class="search-filters--facets-inner">

                <?php if (isset($form['#facets']['field_subject:name'])): ?>
                  <section class="search-filters--facets-facet search-filters--facets-facet-subjects">
                    <header>
                      <h1><?php print t('Subjects') ?></h1>
                    </header>

                    <div class="search-filters--facets-facet-items">
                      <?php
                        foreach ($form['#facets']['field_subject:name'] as $index => $facet) {
                          print theme('loop_search_db_facet', [
                            'index' => $index,
                            'facet' => $facet,
                            'facet_name' => 'subjects',
                            'filter_name' => 'field_subject:name',
                          ]);
                        }
                      ?>
                    </div>
                  </section>
                <?php endif ?>

                <?php if (isset($form['#facets']['field_keyword:name'])): ?>
                  <section class="search-filters--facets-facet search-filters--facets-facet-keywords">
                    <header>
                      <h1><?php print t('Keywords') ?></h1>
                    </header>

                    <div class="search-filters--facets-facet-items">
                      <?php
                        foreach ($form['#facets']['field_keyword:name'] as $index => $facet) {
                          print theme('loop_search_db_facet', [
                            'index' => $index,
                            'facet' => $facet,
                            'facet_name' => 'keywords',
                            'filter_name' => 'field_keyword:name',
                          ]);
                        }
                      ?>
                    </div>
                  </section>
                <?php endif ?>

                <div class="search-filters--action"><?php print t('Filter') ?></div>
              </div>
          <?php endif ?>
        </div>
      <?php endif ?>

      <?php if (isset($form['#sorts'])): ?>
        <div class="search-filters--sort">
          <div class="search-filters--sort-text"><?php print t('Sort results') ?></div>
          <div class="search-filters--sort-labels">
            <?php foreach ($form['#sorts'] as $sort): ?>
              <a href="<?php print $sort['url'] ?>" class="search-filters--label <?php print $sort['active'] ? ' is-active' : '' ?>"><?php print $sort['text']; ?></a>
            <?php endforeach ?>
          </div>
        </div>
      <?php endif ?>

    </div>
  </div>
</div>
