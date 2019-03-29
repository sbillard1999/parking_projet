<?php 
	session_start();
	include("classes/bdd.php");
	include("classes/validateur.php");
?>
<!DOCTYPE html>
	<head>
		<meta charset="UTF-8">
		<title>Connexion validateur</title>
	</head>
	<body>
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
					$bdd = new bdd("192.168.65.143","parking-db","validateur","validateur");
					
					$connexionValide = 0;
					$pdo = $bdd->ObtenirBDD();
					
					$requete = $pdo-> query('SELECT * FROM validateur ') or die(mysql_error());
					echo "ça passe";
					while($resultat = $requete -> fetch())
					{	
						if($_POST['login'] == $resultat['login'] && ($_POST['password']) == $resultat['password'])
						{
							$connexionValide = 1;
						}
					}

					if($connexionValide == 1)
					{
						$_SESSION['connexion'] = true;
						header('location: interface-validateur.php');
					}
					else
					{
						?> <p>Informations erronées!</p> <?php
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