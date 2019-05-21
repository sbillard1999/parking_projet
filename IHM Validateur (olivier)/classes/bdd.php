<?php
	ini_set('display_errors', 1);
	ini_set('display_startup_errors', 1);
	error_reporting(E_ALL);
 
	class bdd{

		private $_database = null;
		
		function __construct($host_database, $name_database, $login_database, $password_database){
			try{
				$this->_database = new PDO('mysql:host='.$host_database.';dbname='.$name_database.';charset=utf8', $login_database, $password_database);
			}
			catch (Exception $error){
				$this->_database = null;
				die('Erreur: '.$error->getMessage());
			}
		}

		public function ObtenirBDD(){
			if(!is_null($this->_database)){			
				return $this->_database;
			}else{
				echo "Base non accessible";
				return null;
			}
		}

		public function ObtenirID($loginValidateur, $passwordValidateur){

			if(!is_null($this->_database)){

				$idValidateur = $this->_database -> query('SELECT `validateur`.`id_validateur` FROM validateur WHERE `login`="'.$loginValidateur.'" AND `password`="'.$passwordValidateur.'" ') or die(print_r($this->_database->errorInfo()));
				
				while($resultat = $idValidateur -> fetch())
				{
					return $resultat["id_validateur"];
				}
			}
			else
			{
				echo "Base non accessible";
				return null;
			}
		}

		public function ConnexionValidateur($loginValidateur, $passwordValidateur){
			if(!is_null($this->_database)){

				$requete = $this->_database->query('SELECT `validateur`.`login`,`validateur`.`password` FROM validateur ') or die(mysql_error());
				$connexionValide = false;

				while($resultat = $requete -> fetch())
				{	
					if($loginValidateur == $resultat['login'] && $passwordValidateur == $resultat['password'])
					{
						$connexionValide = true;
					}
				}
			}
			return $connexionValide;
		}
        
	  	public function InscriptionValidateur($loginNouveauValidateur,$mdpNouveauValidateur){
			$requete = $this->_database -> query('INSERT INTO `validateur` (`login`, `password`) VALUES ("'.$loginNouveauValidateur.'","'.$mdpNouveauValidateur.'")') or die(mysql_error());	 
			?><p style="color:green;">Le nouveau validateur a bien été créé</p><?php
		}

		public function AfficherValidateurs()
		{
			$requete = $this->_database->query('SELECT
													`validateur`.`id_validateur`,
													`validateur`.`login`
												FROM
													`validateur`
												ORDER BY
													`id_validateur`
												ASC'
											 );
			while($resultat = $requete -> fetch())
			{
				echo '<form method="post" action="gerer-validateurs.php">
						<tr>
							<td style="text-align:center; width:110px; height:45px;">'.$resultat["id_validateur"].'</td>
							<td style="text-align:center; width:100px; height:45px;">'.$resultat["login"].'</td>
							<td style="text-align:center; width:170px; height:45px;"><input type="radio" name="selectionValidateur"
									value="'.$resultat["id_validateur"].'" style="cursor:pointer;width:15px;height:15px;"></td>
						</tr>';
			}
				echo '  <tr>
							<td colspan="10" style="padding: 10px;">
								<input type="text" name="newLoginValidateur" placeholder="Nouveau login">
								<input type="password" name="newPasswordValidateur" placeholder="Nouveau mot de passe">
								<input type="submit" name="input" value="Modifier ce validateur">
							</td>
						</tr>
						<tr>
							<td colspan="10" style="padding: 10px;">
								<input type="submit" name="desactiverValidateur" value="Désactiver ce compte">
							</td>
						</tr>
					  </form>';
		}

		public function ModifierValidateur()
		{
			
		}

		public function DesactiverValidateur()
		{

		}
		
		public function EnvoyerMessage($id_validateur, $id_demande, $messageValidateur){
			$requete = $this->_database -> query("INSERT INTO `message-validateur` (`id_validateur`, `id_demande`, `message`) VALUES ('".$id_validateur."','".$id_demande."','".$messageValidateur."')") or die(print_r($this->_database->errorInfo()));
			?><p style="color:green;">Le message a bien été transmis.</p><?php
		}

		public function RechercherDemandes($id_demande, $etat, $email, $immatriculation){
			// à faire
		}

		public function ObtenirEtatDemande($selectionDemande){
			$requete = $this->_database -> query('SELECT `demande`.`etat` FROM demande WHERE `id_demande`="'.$selectionDemande.'" ') or die(print_r($this->_database->errorInfo()));
			
			while($resultat = $requete -> fetch())
			{
				return $resultat['etat'];
			}
		}

		public function ChangerEtatDemande($nouveauEtat, $selectionDemande){
			$requete = $this->_database->query('UPDATE `demande` SET `etat` = "'.$nouveauEtat.'" WHERE `demande`.`id_demande` = "'.$selectionDemande.'"');
		}

		public function AfficherDemandes($etatSelect){
			$requete = $this->_database->query('SELECT 
													`demande`.`id_demande`,
													`demande`.`etat`,
													`proprietaires`.`nom`,
													`proprietaires`.`prenom`,
													`proprietaires`.`email` ,
													`vehicules`.`immatriculation`,
													`vehicules`.`carte_grise`
												FROM
													`demande`,
													`proprietaires`,
													`vehicules`
												WHERE 
													`demande`.`id_proprietaire` = `proprietaires`.`id_proprietaire`
												AND
													`demande`.`id_vehicule` = `proprietaires`.`id_vehicule`
												AND
													`demande`.`id_vehicule` = `vehicules`.`id_vehicule`
												AND 
													`demande`.`etat` = "'.$etatSelect.'"
												ORDER BY
													`id_demande`
												ASC'
											 );

			while($resultat = $requete->fetch())
			{
				switch($resultat["etat"])
				{
					case $resultat["etat"] == 1;
					$resultat["etat"] = "Attente de traitement";
					break;
					
					case $resultat["etat"] == 2;
					$resultat["etat"] = "Attente d'informations";
					break;

					case $resultat["etat"] == 3;
					$resultat["etat"] = "Refusée";
					break;

					case $resultat["etat"] == 4;
					$resultat["etat"] = "Validée";
					break;
				}

				echo '
				<form method="post" action="interface-validateur.php">
					<tr>
						<td style="text-align:center; width:110px; height:45px;">'.$resultat["id_demande"].'</td>
						<td style="text-align:center; width:100px; height:45px;">'.$resultat["etat"].'</td>
						<td style="text-align:center; width:110px; height:45px;">'.$resultat["nom"].'</td>
						<td style="text-align:center; width:170px; height:45px;">'.$resultat["prenom"].'</td>
						<td style="text-align:center; width:170px; height:45px;">'.$resultat["email"].'</td>
						<td style="text-align:center; width:110px; height:45px;">'.$resultat["immatriculation"].'</td>
						<td style="text-align:center; width:170px; height:45px;">'.$resultat["carte_grise"].'</td>
						<td style="text-align:center; width:170px; height:45px;"><input type="radio" name="selectionDemande"
									value="'.$resultat["id_demande"].'" style="cursor:pointer;width:15px;height:15px;"></td>
					</tr>';
			}

					echo '
					<tr>
						<td colspan="10" style="padding: 10px;">
							<input type="submit" name="validerDemande" value="Valider demande">
						</td>
					</tr>
					<tr>
						<td colspan="10" style="padding: 10px;">
							<input type="submit" name="refuserDemande" value="Refuser demande">
						</td>
					</tr>
					<tr>
						<td colspan="10" style="padding: 10px;">
							<input type="submit" name="demanderInformation" value="En attente d\'informations">
							<textarea name="messageValidateur" cols="83" maxlength="3000" placeholder="Écrivez votre message au demandeur..."></textarea>
						</td>
					</tr>
				</form>';
		}
		
		public function AfficherPassages(){
			$requete = $this->_database->query('SELECT 
													`passages`.`id_passage`,
													`passages`.`horodatage`,
													`passages`.`immatriculation`
												FROM
													`passages`
												ORDER BY
													`horodatage`
												DESC'
											);
																				
			while($resultat = $requete->fetch())
			{
				echo '
				<tr>
					<td style="text-align:center; width:110px; height:45px;">'.$resultat["id_passage"].'</td>
					<td style="text-align:center; width:110px; height:45px;">'.$resultat["horodatage"].'</td>
					<td style="text-align:center; width:110px; height:45px;">'.$resultat["immatriculation"].'</td>
				</tr>';
			}
	    }
	}
?>