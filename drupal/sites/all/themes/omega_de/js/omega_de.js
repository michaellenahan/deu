(function ($) {

  Drupal.behaviors.omega_de = {
    attach: function (context, settings) {
      $('img', context).bind("contextmenu", function () {
        return false;
      });
      $('img', context).bind("dragstart", function (event) {
        event.preventDefault();
      });
    }
  };

})(jQuery);
