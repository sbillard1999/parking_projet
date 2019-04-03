
<?php 
session_start(); 
include("../identification/bddclass.php");
?>
<!DOCTYPE html> 
<html>
<head> 
<title>Login Parknig</title> 
</head> 
<body> 

<?php 
    //on vérifie que le formulaire est rempli et qu'on appuie bien sur le bouton 
    if (isset($_POST['button']) && !empty($_POST['name']) && !empty($_POST['password'])) 
    {
        $Utilisateur = new BDD($_POST['username'],$_POST['password'],'192.168.65.143','parking-db','root','root'); 
        $Utilisateur->compare('login');
        if($Utilisateur->isConnect()) 
        { 
            echo"Connexion réussi!"; 
            $_SESSION['nom']=$_POST['nom']; 
            $_SESSION['password']=$_POST['password']; 
            $_SESSION['email']=$_POST['email']; 
        } 
        else 
        { 
            echo "Erreur: Login ou password incorrect!"; 
        } 
    }
    //instance de l'objet de la classe utilisateur pour stocker dans la Session 
    if(isset($_SESSION['username'])) 
    {
        $Utilisateur = new BDD($_SESSION['username'],$_SESSION['password'],'192.168.65.143','parking-db','root','root'); 

        ?> 
        <form action="index.php" method="post"> 
        <input type="submit" id="button" name="deconnexion" value="DECONNEXION"> 
        </form> 
        <?php 
    } 
    else 
    { 
    //formulaire de connexion 
?> 
<div id="container"> 
    <h3>CONNEXION</h3> 
    <form action="connexion.php" method="post"> 
        <label>LOGIN<br> 
            <input type="text" id="box" name="name"></label><br> 
        <label>PASSWORD<br> 
            <input type="password" id="box" name="password"></label> 
            <input type="submit" id="button" name="button" value="CONNEXION"><br> 
        <a href="index_inscription.php"> Inscription </a> 
        
    </form> 
</div>
<?php 
} 
//destruction de la variable SESSION 
if (isset($_POST['deconnexion'])) 
{ 
session_unset(); 
session_destroy(); 
}
?>

</body> 
</html>

