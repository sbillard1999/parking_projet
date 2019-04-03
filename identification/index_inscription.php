<?php include("bddclass.php") ?>
<!DOCTYPE html>
 
<html>
<head> 
<meta charset="utf-8">
<title>Login Parking</title> 
</head> 
<body> 

<?php
//on vérifie que le formulaire est rempli et qu'on appuie bien sur le bouton 
if (isset($_POST['button2']) && !empty($_POST['username2']) && !empty($_POST['password2']) && !empty($_POST['email2']) && !empty($_POST['nom2']) && !empty($_POST['prenom2'])) 
    {
    
    $Utilisateur = new BDD($_POST['username2'],$_POST['password2'],'localhost','parking-db','root','');
   
    $id=$Utilisateur->GetLastIdVehicule();
    
    //appelle de la fonction inscription
    $Utilisateur->inscription($_POST['nom2'],$_POST['prenom2'],$_POST['email2'],$_POST['username2'],$_POST['password2'],$id);
    $etat=$Utilisateur->GetEtatInscription();
    if($etat==true)
    {
        echo "Inscription réussie !";
        echo "<br>";
    }
    else
    {
        echo  "Inscription incorrect !";
        echo "<br>";
    }
}

   
//formulaire d'inscription 
?>
<div id="container2"> 
    <h3>INSCRIPTION</h3> 
    <form action="index_inscription.php" method="post"> 
        <label>LOGIN<br> 
            <input type="text" id="box" name="username2"></label></br> 
        <label>PASSWORD<br> 
            <input type="password" id="box" name="password2"></label></br> 
        <label>EMAIL<br> 
            <input type="email" id="box" name="email2"></label></br>
        <label>NOM<br> 
            <input type="text" id="box" name="nom2"></label></br> 
        <label>PRENOM<br> 
            <input type="text" id="box" name="prenom2"></label></br> 

        <input type="submit" id="button2" name="button2" value="INSCRIPTION"></br> 
        <a href="index.php"> Connexion </a> 
    </form> 
</div>

</body> 
</html>