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
        <?php if (isset($form['#facets']['type'])): ?>
          <div class="search-filters--type">
            <?php foreach ($form['#facets']['type'] as $index => $facet): ?>
              <?php $name = 'f[]'; ?>
              <?php $text = trim($facet['filter'], '"'); ?>
              <?php $value = $text ? urlencode('type').':'.$text : ''; ?>
              <?php $checked = $facet['active'] ?? FALSE; ?>
              <label class="search-filters--label <?php if ($checked) { print ' is-active '; } ?>"><?php print $facet['text'] ?? $facet['filter']; ?>
                <input type="checkbox" name="<?php print $name; ?>" <?php if ($checked) { print ' checked '; } ?> value="<?php print htmlspecialchars($value) ?>"/>
              </label>
            <?php endforeach ?>
          </div>
        <?php endif ?>

        <?php if (isset($form['#facets']['field_subject:name'])): ?>
          <span class="search-filters--subject-wrapper">
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
                <?php foreach ($form['#facets']['field_subject:name'] as $index => $facet): ?>
                  <?php $key = 'field_subject:name-'.$index; ?>
                  <?php $name = 'f[]'; ?>
                  <?php $text = $facet['filter']; ?>
                  <?php $value = urlencode('field_subject:name').':'.$text; ?>
                  <?php $checked = $facet['active'] ?? FALSE; ?>

                  <div class="search-filters--subjects-item">
                    <span class="search-filters--subjects-item-inner">
                      <input id="<?php print $key; ?>" type="checkbox" name="<?php print $name; ?>" <?php if ($checked) { print ' checked '; } ?> value="<?php print htmlspecialchars($value) ?>"/>
                      <label for="<?php print $key; ?>"><?php print $text; ?></label>
                    </span>
                  </div>
                <?php endforeach ?>
              </div>
              <span class="search-filters--action"><?php print t('Filter') ?></span>
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