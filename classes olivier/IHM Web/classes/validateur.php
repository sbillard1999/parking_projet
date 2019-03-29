<?php
	class validateur
	{
		private $_loginValidateur;
		private $_nomValidateur;
		private $_mdpValidateur;
		private $_connect = false;	

		function __construct($loginValidateur,$mdpValidateur){
			//initialise les identifiants du validateur
			$this->_loginValidateur = $loginValidateur; 
			$this->_mdpValidateur = $mdpValidateur;
		}

		//accesseur -------------------
		public function ObtenirLoginValidateur(){
			return $this->_nomValidateur;
		}

		public function isConnect(){
			return $this->_connect;
		}

		//méthode qui va vérifier si utilisateur peut se connecter
		public function ConnexionValidateur($bdd, $table, $champLogin, $champPassword){
			
			//teste si $_loginValidateur et $_mdpValidateur existe dans la base 
			if( $bdd->ConnexionValidateur($this->_loginValidateur, $this->_mdpValidateur, $table, $champLogin, $champPassword)){
				return $this->_connect = true;
			}else{
				return $this->_connect = false;
			}
		}
	}
?>
