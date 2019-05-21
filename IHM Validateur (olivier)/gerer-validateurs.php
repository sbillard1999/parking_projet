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
				<title>Gérer les validateurs</title>
			</head>
			<body bgcolor="#c6c7c7">
			
				<form action="gerer-validateurs.php" method="post">
					<h3>Déconnecter votre session:</h3>
					<input type="submit" name="btnDeconnexion" value="Se déconnecter">
				</form>
			
				<?php
					//$bdd = new bdd("127.0.0.1","parking-db","root","");
					$bdd = new bdd("192.168.65.143","parking-db","validateur","validateur");
				?>

				</br>
				<!-- Affichage des validateurs -->
				
				<table border="1" style="background-color:#eaebed; color:#135D95; font-family:Tahoma;">
					<tr>
						<th style="text-align:center; width:110px; height:45px;">ID Validateur</th>
						<th style="text-align:center; width:110px; height:45px;">Login</th>
					</tr>

					<?php

                        $bdd->AfficherValidateurs();

                        if(isset($_POST['selectionValidateur']))
                        {

                        }
                        else
                        {
							?> <p style="color:red;">Aucun compte de validateur n'est sélectionné</p> <?php
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