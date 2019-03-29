<?php
	session_start();
	include("classes/bdd.php");
	include("classes/validateur.php");


	if (isset($_POST['btnDeconnexion']))
	{
		session_unset();
		session_destroy();
		header('Location: index.php');
	}

	if(isset($_SESSION['connexion']) && $_SESSION['connexion'] == true)
	{
		?>

		<!DOCTYPE html>
			<head>
				<meta charset="utf-8">
				<title>Interface de validation</title>
			</head>
			<body>
				<form action="interface-validateur.php" method="post">
					<input type="text" name="validateur" placeholder="Nom du nouveau validateur">
					<input type="password" name="password" placeholder="Mot de passe du validateur">
					<input type="submit" name="btnInscription" value="Créer un nouveau validateur">
					<input type="submit" name="btnDeconnexion" value="Se déconnecter">
				</form>
			
				<?php
				
					$bdd = new bdd("192.168.65.143","parking-db","validateur","validateur");
				
					if(isset($_POST['btnInscription']))
					{
						if(isset($_POST['validateur']) && !empty($_POST['validateur']) && isset($_POST['password']) && !empty($_POST['password']))
						{
							$requete=$bdd->InscriptionValidateur($_POST['validateur'],$_POST['password']);
							echo "Un nouveau validateur vient d'être créé !";
							
						}else{
							echo"Champs vides !";
						}
					}

				?>

				</br>
				<form method="post" action="interface-validateur.php">
					<input type="text" name="idDemande" placeholder="Insérer l'ID d'une demande">
					<input type="text" name="etatDemande" placeholder="">
					<input type="text" name="" placeholder="">
					<input type="submit" name="btnRechercher" value="Rechercher">
				</form>
				</br>
					
				<table border="1" style="color:#135D95; font-family:Tahoma;">
					<tr>
						<th style="text-align:center; width:110px; height:45px;">ID Demande</th>
						<th style="text-align:center; width:110px; height:45px;">État de la demande</th>
						<th style="text-align:center; width:110px; height:45px;">Nom</th>
						<th style="text-align:center; width:110px; height:45px;">Prénom</th>
						<th style="text-align:center; width:110px; height:45px;">E-mail</th>
						<th style="text-align:center; width:150px; height:45px;">Immatriculation</th>
						<th style="text-align:center; width:170px; height:45px;">Carte grise</th>
						<th style="text-align:center; width:1000px;height:45px;">Message</th>
						<th style="text-align:center; width:170px; height:45px;">Date d'expiration</th>
					</tr>

					<?php
						$bdd->AfficherTableau();
					?>

				</table>
			</body>
		</html>
		<?php
	}else{
		header('location: index.php');
	}
?>