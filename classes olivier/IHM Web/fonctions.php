<?php 
	function ConnexionBDD($host,$dbname,$user,$password)
	{
		try{
			$database = new PDO('mysql:host='.$host.';dbname='.$dbname.';charset=utf8', $user, $password);
			return $database;
		}
		catch (Exception $error)
		{
			die('Erreur: '.$error->getMessage());
		}
	}
?>