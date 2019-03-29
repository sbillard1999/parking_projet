<?php 
	class bdd{

		private $_database = null;

		public function ObtenirBDD(){
			if(!is_null($this->_database)){			
				return $this->_database;
			}else{
				echo "Base non accessible";
				return null;
			}
		}
		
		function __construct($host_database, $name_database, $login_database, $password_database){
			try{
				$this->_database = new PDO('mysql:host='.$host_database.';dbname='.$name_database.';charset=utf8', $login_database, $password_database);
			}
			catch (Exception $error){
				$this->_database = null;
				die('Erreur: '.$error->getMessage());
			}
		}

		public function ConnexionValidateur($loginValidateur, $passwordValidateur, $table, $champLogin, $champPassword){
			if(!is_null($this->_database)){
				$requete = $this->_database->query("SELECT * FROM `".$table."` WHERE ".$champLogin."='".$this->_loginValidateur."' AND ".$champPassword."='".$this->_passwordValidateur."'");

				// connexion autorisée ou non
				if ($requete->rowCount()==1){
					return true;
				}
			}
			return false;
        }
        
	    public function InscriptionValidateur($validateur,$mdp)
	    {

			$nouveauValidateur = $validateur;
			$password = $mdp;
			$requete = $this->_database -> query("INSERT INTO `validateur` (login, password) VALUES ('".$nouveauValidateur."','".$password."')") or die(mysql_error());	 
			return $requete;
	    }

		public function AfficherTableau()
	    {
			$requete = $this->_database->query('SELECT `id_demande`, `etat`, `message`, `expiration`,`nom`, `prenom`, `email`,`immatriculation`, `carte_grise` FROM `demande`,`proprietaires`,`vehicules` WHERE `demande`.`id_proprietaire`=`proprietaires`.`id_proprietaire`=`vehicules`.`id_proprietaire` AND `demande`.`id_vehicule`=`proprietaires`.`id_vehicule`=`vehicules`.`id_immatriculation`  ORDER BY id_demande ASC');
	
			while($resultat = $requete->fetch())
			{
				/* A REPLACE DANS L'ORDRE CAR DONNEES EN DESORDRE DANS LE TABLEAU */	
				echo '<tr>
				
				<td style="text-align:center; width:110px; height:45px;">'.$resultat["id_demande"].'</td>
				<td style="text-align:center; width:110px; height:45px;">'.$resultat["etat"].'</td>
				<td style="text-align:center; width:1000px;height:45px;">'.$resultat["message"].'</td>
				<td style="text-align:center; width:170px; height:45px;">'.$resultat['expiration'].'</td>
				<td style="text-align:center; width:110px; height:45px;">'.$resultat['nom'].'</td>
				<td style="text-align:center; width:170px; height:45px;">'.$resultat["prenom"].'</td>
				<td style="text-align:center; width:170px; height:45px;">'.$resultat["email"].'</td>
				<td style="text-align:center; width:110px; height:45px;">'.$resultat["immatriculation"].'</td>
				<td style="text-align:center; width:170px; height:45px;">'.$resultat["carte_grise"].'</td><td style="text-align:center; width:170px; height:45px;"><input type="checkbox" name="selection[]" value="'.$resultat["id_demande"].'" style="cursor:pointer;width:15px;height:15px;"></td>';
			} 
						
			echo'</tr>';
	  	 }
	}
?>