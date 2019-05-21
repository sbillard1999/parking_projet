<?php 
	session_start();
	include("classes/bdd.php");
	ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

?>
<!DOCTYPE html>
	<head>
		<meta charset="UTF-8">
		<title>Connexion validateur</title>
	</head>
	<body bgcolor="#c6c7c7">
		<form action="index.php" method="post">
			<input type="text" name="login" placeholder="Nom validateur">
			<input type="password" name="password" placeholder="Mot de passe">
			<input type="submit" name="connexion" value="Se connecter">
		</form>
		<?php
		
			if(isset($_POST['connexion']))
			{
				
				if(isset($_POST['login']) && !empty($_POST['login']) && isset($_POST['password']) && !empty($_POST['password']))
				{
					//$bdd = new bdd("127.0.0.1","parking-db","root","");
					$bdd = new bdd("192.168.65.143","parking-db","validateur","validateur");
					
					$connexionValide = false;
					$database = $bdd -> ObtenirBDD();

					$loginValidateur = $_POST['login'];
					$passwordValidateur = $_POST['password'];

					$connexionValide = $bdd -> ConnexionValidateur($loginValidateur, $passwordValidateur);

					if($connexionValide == true)
					{
						$_SESSION['validateur'] = true;
						$session = $bdd -> ObtenirID($loginValidateur, $passwordValidateur);
						$_SESSION['idValidateur'] = $session;
						
						header('location: interface-validateur.php');
					}
					else
					{
						?> <p>Mauvais identifiants!</p> <?php
					}
				}
				else
				{
					?> <p>Champs vides!</p> <?php
				}
			}
		?>
	</body>
</html>