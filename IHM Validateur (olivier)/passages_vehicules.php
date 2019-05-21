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
				<title>Interface de validation: passages des véhicules</title>
			</head>
			<body bgcolor="#c6c7c7">

                <form action="passages_vehicules.php" method="post">
                    <input type="submit" name="btnAfficherInterface" value="Revenir sur l'interface de validation"></br></br>
					<input type="submit" name="btnDeconnexion" value="Se déconnecter">
				</form> 

                <?php
                    //$bdd = new bdd("127.0.0.1","parking-db","root","");
                    $bdd = new bdd("192.168.65.143","parking-db","validateur","validateur");
                    
                    if(isset($_POST['btnAfficherInterface']))
                    {
                        header("location: interface-validateur.php");
                    }
                ?>

                </br>
                <table border="1" style="background-color:#eaebed; color:#135D95; font-family:Tahoma;">
					<tr>
						<th style="text-align:center; width:110px; height:45px;">ID Passage</th>
						<th style="text-align:center; width:110px; height:45px;">Horodatage</th>
						<th style="text-align:center; width:110px; height:45px;">Immatriculation</th>
					</tr>
                    <?php
                        $bdd->AfficherPassages();
                    ?>
                </table>
			</body>
		</html>
		<?php
	}else{
		header('location: index.php');
	}
?>