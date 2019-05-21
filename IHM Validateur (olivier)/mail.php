<?php
 
    ini_set( 'display_errors', 1 );
 
    error_reporting( E_ALL );

    include "mailtest.php";

    $test = new Mail("oboulanger@la-providence.net","test","test");

    $test->EnvoiMail();
 
    // $from = "test@ts-pro.fr";
 
    // $to = "oboulanger@la-providence.net";
 
    // $subject = "Test email automatique";
 
    // $message = "Test message email php";
 
    // $headers = "From:" . $from;
 
    // mail($to,$subject,$message, $headers);
 
    // echo "L'email a été envoyé.";
?>