<!-- $swf_path variable stores the location of the swf file to be used in: -->
<!-- swfobject.embedSWF() below. -->
<?php $swf_uri = $node->field_swf_file['und'][0]['uri']; ?>
<?php $swf_path = str_replace('private://', '/system/files/', $swf_uri); ?>

<article<?php print $attributes; ?>>
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted): ?>
  <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
  <?php endif; ?>  

  <script type="text/javascript" src="/sites/all/libraries/swfobject/swfobject.js"></script>
  <script type="text/javascript">
    var flashvars = {};
    var params = {};
    // uncomment to disable right-click menu
    //params.menu = "false";
    var attributes = {};
    //swfobject.embedSWF("/sites/default/files/136.swf", "myAlternativeContent", "1191", "842", "9.0.0", "expressInstall.swf", flashvars, params, attributes);
    swfobject.embedSWF("<?php echo $swf_path ?>", "myAlternativeContent", "1191", "842", "9.0.0", "expressInstall.swf", flashvars, params, attributes);
  </script>

  <div id="myAlternativeContent">
    <a href="http://www.adobe.com/go/getflashplayer">
      <img src="http://www.adobe.com/images/shared/download_buttons/get_flash_player.gif" alt="Get Adobe Flash player" />
    </a>
  </div>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content);
    ?>
  </div>
  
  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>
</article>
