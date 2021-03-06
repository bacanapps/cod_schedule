<?php

/**
 * @file
 * COD Schedule cod_schedule_views_plugin_style_schedule.inc file.
 */

/**
 * Style plugin to render sessions in a grid.
 *
 * @ingroup views_style_plugins
 */
class CodScheduleViewsPluginStyleSchedule extends views_plugin_style_table {

  function option_definition() {
    $options = parent::option_definition();

    $options['caption'] = array('default' => '', 'translatable' => TRUE);
    $options['summary'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }


  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $handlers = $this->display->handler->get_handlers('field');
    if (empty($handlers)) {
      $form['error_markup'] = array(
        '#markup' => '<div class="error messages">' . t('You need at least one field before you can configure your table settings') . '</div>',
      );
      return;
    }

    $form['caption'] = array(
      '#type' => 'textfield',
      '#title' => t('Short description of table'),
      '#description' => t('Include a caption for better accessibility of your table.'),
      '#default_value' => $this->options['caption'],
      '#maxlength' => 255,
    );

    $form['summary'] = array(
      '#type' => 'textfield',
      '#title' => t('Table summary'),
      '#description' => t('This value will be displayed as table-summary attribute in the html. Use this to give a summary of complex tables.'),
      '#default_value' => $this->options['summary'],
      '#maxlength' => 255,
    );
  }



}
