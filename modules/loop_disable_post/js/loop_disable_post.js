/**
 * @file
 * Hide specific views and sections that are related to post.
 */
(function ($) {
  "use strict";
  $(document).ready(function($) {
    $('.layout-dashboard .layout--inner:first-child').addClass('is-hidden');
    $('.view-loop-user-subscriptions').addClass('is-hidden');
  });
})(jQuery);
