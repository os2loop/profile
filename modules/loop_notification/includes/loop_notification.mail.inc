<?php

/**
 * Doc comment is empty.
 */
class LoopNotificationHtmlMail implements MailSystemInterface {
  /**
   * The format class.
   *
   * @var \MailSystemInterface
   */
  protected $formatClass;

  /**
   * The mail class.
   *
   * @var \MailSystemInterface
   */
  protected $mailClass;

  /**
   * Constructor.
   */
  public function __construct() {
    if (drupal_autoload_class('HTMLMailSystem')) {
      $this->formatClass = new HTMLMailSystem();
    }
    else {
      $this->formatClass = new DefaultMailSystem();
    }
    if (drupal_autoload_class('SmtpMailSystem')) {
      $this->mailClass = new SmtpMailSystem();
    }
    else {
      $this->mailClass = new DefaultMailSystem();
    }
  }

  /**
   * {@inheritdoc}
   */
  public function format(array $message) {
    return $this->formatClass->format($message);
  }

  /**
   * {@inheritdoc}
   */
  public function mail(array $message) {
    return $this->mailClass->mail($message);
  }

}
