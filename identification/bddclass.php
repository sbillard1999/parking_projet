<?php

class BDD{ 

	private $login;
	private $motdepasse;
	private $Connect=false;
	private $base;
	private $EtatInscription = false;
	
 


	public function __construct($login,$motdepasse,$adresse,$dbname,$nameuser,$mdp){

		$this->login=$login;
		$this->motdepasse=$motdepasse;
		$this->connexionbdd($adresse,$dbname,$nameuser,$mdp);
	}

	public function connexionbdd($adresse,$dbname,$nameuser,$mdp)
	{	
		try{
			
				$this->base = new PDO('mysql:host='.$adresse.';dbname='.$dbname.';charset=utf8',''.$nameuser.'',''.$mdp.'');
				//$base = new PDO('mysql:host=192.168.65.143;dbname=parking-db;charset=utf8','validateur','validateur');
	    		//echo "<br> connecte a la bbd";
	    		$this->Connect=true;
	    	
			}
			  
	  	catch(PDOexception $e) 
			{
				
				$this->Connect = false;
			}
				

		if ($this->Connect == true) 
			{
				echo "Connecté à la BDD";
				echo "<br>";
			} 
		else{
				echo "Problème connexion BDD";
				echo "<br>";
			} 	  



	}





	public function isConnect(){

	return $this->Connect;
	}

	//Compare la BDD avec les informations rentrées dans le formulaire 
	public function compare($table) 
	{ 
		$reponse=$this->base->query("SELECT * FROM ".$table." WHERE `login`= '".$this->login."' AND `password` = '".$this->motdepasse."'"); 

		while($answer=$reponse->fetch())
		{
			if($answer[5]==$this->login && $answer[6]==$this->motdepasse)
			{
				return true;
			}
		}
		
	}
//cette fonction permet de s'inscrire à la bdd 
	public function inscription($nom,$prenom,$email,$login,$mdp,$id_vehicule) 
	{ 


		$requete="INSERT INTO `proprietaires` (`id_vehicule`,`nom`,`prenom`,`email`,`login`,`password`)
		VALUES (".$id_vehicule.",'".$nom."','".$prenom."','".$email."','".$login."','".$mdp."')";

		if($this->base->query($requete))
		{ 
			$this->EtatInscription= true;
		} 
		else 
		{ 
			$this->EtatInscription= false;
		} 
	

	}
	public function GetEtatInscription()
	{
		return $this->EtatInscription;
	}
	public function GetLastIdVehicule()
	{
		$requete="SELECT `id_vehicule` FROM `proprietaires` ORDER BY `id_vehicule` DESC LIMIT 1";
		$reponse =$this->base->query($requete);
		while($answer=$reponse->fetch())
		{
				return $answer[0]+1;
		}

	
	}
}
?>
