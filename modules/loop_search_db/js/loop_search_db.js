/**
 * @file
 * Auto complete attachment for search in Drupal.
 */

/**
 * Helper function to get hostname of a link.
 *
 * @param data
 *   Full link.
 *
 * @returns {string}
 *   Hostname of full link.
 */
function url_domain(data) {
  var a = document.createElement('a');
  a.href = data;
  return a.hostname;
}

/**
 * Default ready function.
 *
 * Prefetch nodes.
 * Start typeahead.
 */
jQuery(document).ready(function($) {
  "use strict";

  var settings = {
    highlight: true
  };

  LoopSearch.unshift(settings);

  // Apply our global search Bloodhound(s).
  var typeaheadElement = $('.typeahead');
  typeaheadElement.typeahead.apply(typeaheadElement, LoopSearch);

  typeaheadElement.on('typeahead:selected', function (object, datum) {
    // If suggestion contains a link. Redirect.
    if (datum.link !== undefined) {
      var linkDomain = url_domain(datum.link);
      var currentDomain = window.location.hostname;

      // Open external links in a new window.
      // IE9: url_domain() will return '' for relative links for domain,
      //   that is the reason for the first condition below.
      if (linkDomain !== '' && linkDomain !== currentDomain) {
        window.open(datum.link);
      }
      else {
        window.location = datum.link;
      }
    }
    else {
      // Suggestion is clicked. Display the results.
      typeaheadElement.blur().focus();
    }
  });

  // On search form submit disable submit button.
  $('form.js--search').submit(function () {
    $(this).find('[type=submit]')
      .attr('disabled', true)
      .val(Drupal.t('Searching ...'));
  });

  /**
   * Helper function to get hostname of a link.
   *
   * @param data
   *   Full link.
   *
   * @returns {string}
   *   Hostname of full link.
   */
  function url_domain(data) {
    var a = document.createElement('a');
    a.href = data;

    return a.hostname;
  }

  var $facetsContainer = $('.search-filters--facets')
  $facetsContainer.toggle(false)
  $('.search-filters--facets-wrapper').on('click', function () {
    var $target = $facetsContainer
    $target.toggle($target.is(":hidden"))
  })

  var applyFilters = function() {
    var $form = $(this).closest('form')
    $form.submit()
  }

  $('.search-filters--type :input').on('change', function () {
    // Make sure that on the target is selected.
    $('.search-filters--type :input').prop('checked', false)
    $(this).prop('checked', true)
    applyFilters.apply(this)
  })

  $('.search-filters--action').on('click', function () {
    applyFilters.apply(this)
  })
});
