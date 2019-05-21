<?php
	session_start();
	include("classes/bdd.php");
	ini_set('display_errors', 1);
	ini_set('display_startup_errors', 1);
	error_reporting(E_ALL);

	if (isset($_POST['btnDeconnexion']))
	{
		session_unset();
		session_destroy();
		header('Location: index.php');
	}

	if(isset($_SESSION['validateur']) && $_SESSION['validateur'] == true && isset($_SESSION['idValidateur']))
	{
		?>

		<!DOCTYPE html>
			<head>
				<meta charset="utf-8">
				<title>Interface de validation</title>
			</head>
			<body bgcolor="#c6c7c7">
			
				<form action="interface-validateur.php" method="post">

					<h3>Gestion des utilisateurs (validateurs):</h3>
					<input type="text" name="validateur" placeholder="Nom du nouveau validateur">
					<input type="password" name="password" placeholder="Mot de passe du validateur">
					<input type="submit" name="btnInscription" value="Créer un nouveau validateur"></br></br>
					<input type="submit" name="btnGererValidateurs" value="Modifier/Désactiver un validateur"></br></br>

					<h3>Visionner l'historique de passage des véhicules:</h3>
					<input type="submit" name="btnAfficherPassages" value="Afficher les passages des véhicules"></br></br>

					<h3>Déconnecter votre session:</h3>
					<input type="submit" name="btnDeconnexion" value="Se déconnecter">
				</form>
			
				<?php

					//Inscription d'un nouveau validateur
				
					//$bdd = new bdd("127.0.0.1","parking-db","root","");
					$bdd = new bdd("192.168.65.143","parking-db","validateur","validateur");
				
					if(isset($_POST['btnInscription']))
					{
						if(isset($_POST['validateur']) && !empty($_POST['validateur']) && isset($_POST['password']) && !empty($_POST['password']))
						{
							$loginNouveauValidateur = $_POST['validateur'];
							$mdpNouveauValidateur = $_POST['password'];
							$requete = $bdd->InscriptionValidateur($loginNouveauValidateur,$mdpNouveauValidateur);
						}
						else
						{
							?><p>Champs vides !</p><?php
						}
					}

					if(isset($_POST['btnGererValidateurs']))
					{
						header('location: gerer-validateurs.php');
					}

					if(isset($_POST['btnAfficherPassages']))
					{
						header('location: passages_vehicules.php');
					}
				?>

				</br>
				<!-- Sélectionne l'état à afficher seul -->

				<h3>Choisir d'afficher un "état" spécifique:</h3>

				<form method="post" action="interface-validateur.php">
					<select name="etatSelect">
						<option name="attenteTraitement" value="1">Attente de traitement</option>
						<option name="attenteInfos" value="2">Attente d'informations</option>
						<option name="refusée" value="3">Refusée</option>
						<option name="validée" value="4">Validée</option>
					</select>

					<input type="submit" name="btnAfficher" value="Sélectionner cet état">
				</form>

				</br>
				<!-- Affichage de toutes les demandes -->
				
				<table border="1" style="background-color:#eaebed; color:#135D95; font-family:Tahoma;">
					<tr>
						<th style="text-align:center; width:110px; height:45px;">ID Demande</th>
						<th style="text-align:center; width:110px; height:45px;">État de la demande</th>
						<th style="text-align:center; width:110px; height:45px;">Nom</th>
						<th style="text-align:center; width:110px; height:45px;">Prénom</th>
						<th style="text-align:center; width:110px; height:45px;">E-mail</th>
						<th style="text-align:center; width:150px; height:45px;">Immatriculation</th>
						<th style="text-align:center; width:170px; height:45px;">Carte grise</th>
					</tr>

					<?php

						$etatSelect = 1;

						if(isset($_POST['etatSelect']))
						{
							$etatSelect = $_POST['etatSelect'];
						}	

						$bdd->AfficherDemandes($etatSelect);

						/* Traitement des demandes */

						if(isset($_POST['selectionDemande']))
						{
							$selectionDemande = $_POST['selectionDemande'];
							$etatDemande = $bdd -> ObtenirEtatDemande($selectionDemande);

							switch($selectionDemande)
							{
								/************************ cas 1 ************************/

								case isset($_POST['validerDemande']) == true;
								if($etatDemande != 4)
								{
									$bdd->ChangerEtatDemande("4", $selectionDemande);
									?><p style="color:green;">La demande a bien été validée!</p><?php
								}
								else
								{
									?><p style="color:red;">Cette demande a déjà été validée!</p><?php
								}
								break;

								/************************ cas 2 ************************/

								case isset($_POST['refuserDemande']) == true;
								if($etatDemande != 3)
								{
									$bdd->ChangerEtatDemande("3", $selectionDemande);
									?><p style="color:green;">La demande a bien été refusée!</p><?php
								}
								else
								{
									?><p style="color:red;">Cette demande a déjà été refusée!</p><?php
								}
								break;

								/************************ cas 3 *************************/

								case isset($_POST['demanderInformation']) == true;
								if($etatDemande != 2)
								{
									$bdd->ChangerEtatDemande("2", $selectionDemande);
									if(isset($_POST['messageValidateur']))
									{
										$messageValidateur = $_POST['messageValidateur'];
										$id_demande = $_POST['selectionDemande'];
										$id_validateur = $_SESSION['idValidateur'];

										$bdd -> EnvoyerMessage($id_validateur, $id_demande, $messageValidateur);
									}
									?><p style="color:green;">La demande est bien passée en "attente d'informations".</p><?php
								}
								else
								{
									?><p style="color:red;">Cette demande est déjà en attente d'informations!</p><?php
								}
								break;

								default:
								?><p>Aucune modification n'a été réalisée.</p><?php
							}
						}
						else
						{
							?> <p style="color:red;">Aucune demande n'est sélectionnée</p> <?php
						}
						
					?>
				</table>
			</body>
		</html>
		<?php
	}else{
		header('location: index.php');
	}
?>