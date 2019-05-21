        <?php



class Mail
{
    private $to;
    private $sujet;
    private $from;
    private $headers;
    private $message;
    private $nom;
    
    
    function __construct($mail,$subject,$nomClient) 
    {
        $this->to=$mail;
        $this->nom=$nomClient;
        $this->sujet=$subject;
        $this->from = 'test@ts-pro.fr';
         // Prépare les headers poru envoyer un mail au format HTML
         $this->headers  = 'MIME-Version: 1.0' . "\r\n";
         $this->headers .= 'Content-type: text/html; charset=UTF-8' . "\r\n";
         
         // Créer les headers
         $this->headers .= 'From: '.$this->from."\r\n".
             'Reply-To: '.$this->from."\r\n" .
             'X-Mailer: PHP/' . phpversion();
         
         // Prépare le message 
         $this->message = '<html><body>';
         $this->message .= '<h1 style="color:#f40;">Demande accès parking de la Providence</h1>';
         $this->message .= '<p style="color:#080;font-size:18px;">Monsieur '.$this->nom.'Votre demande d accès par véhicule est bien en cours de traitement, Vous receverez un autre email une fois votre demande traitée  </p>';
         $this->message .= '</body></html>';

    }
    function EnvoiMail()
    {
           // Envoye le Mail
           if(mail($this->to, $this->sujet, $this->message, $this->headers)){
            echo 'Le Mail a bien été envoyé';
        } else{
            echo "L'envoi du mail a échoué.";
        }
    }
}
                
            
                
              
                
             
                ?>