-- phpMyAdmin SQL Dump
-- version 4.6.6deb4
-- https://www.phpmyadmin.net/
--
-- Client :  localhost:3306
-- Généré le :  Ven 03 Mai 2019 à 11:51
-- Version du serveur :  10.1.37-MariaDB-0+deb9u1
-- Version de PHP :  7.0.33-0+deb9u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `parking-db`
--

-- --------------------------------------------------------

--
-- Structure de la table `demande`
--

CREATE TABLE `demande` (
  `id_demande` int(11) NOT NULL,
  `id_proprietaire` int(11) NOT NULL,
  `id_vehicule` int(11) NOT NULL,
  `etat` int(4) NOT NULL,
  `expiration` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `demande`
--

INSERT INTO `demande` (`id_demande`, `id_proprietaire`, `id_vehicule`, `etat`, `expiration`) VALUES
(1, 1, 1, 1, '2019-12-30'),
(2, 2, 2, 3, '2020-01-10'),
(3, 3, 3, 4, '2020-02-15'),
(4, 4, 4, 2, '2020-03-20'),
(5, 5, 5, 4, '2019-08-30'),
(15, 1, 24, 1, '2019-04-30');

-- --------------------------------------------------------

--
-- Structure de la table `message-validateur`
--

CREATE TABLE `message-validateur` (
  `id_message` int(20) NOT NULL,
  `id_validateur` int(20) NOT NULL,
  `id_demande` int(20) NOT NULL,
  `message` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `message-validateur`
--

INSERT INTO `message-validateur` (`id_message`, `id_validateur`, `id_demande`, `message`) VALUES
(29, 16, 5, 'test'),
(32, 16, 5, ''),
(33, 16, 5, 'test'),
(34, 16, 5, 'test2');

-- --------------------------------------------------------

--
-- Structure de la table `passages`
--

CREATE TABLE `passages` (
  `id_passage` int(11) NOT NULL,
  `horodatage` datetime NOT NULL,
  `id_vehicule` int(11) NOT NULL,
  `immatriculation` varchar(12) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `passages`
--

INSERT INTO `passages` (`id_passage`, `horodatage`, `id_vehicule`, `immatriculation`) VALUES
(1, '2019-03-19 08:17:00', 1, 'AB-111-CD'),
(2, '2019-03-20 00:00:00', 1, 'AB-111-CD'),
(4, '2019-05-02 10:10:10', 4, 'MN-444-OP'),
(5, '2019-05-03 20:20:20', 1, 'AB-111-CD'),
(6, '2019-05-03 21:33:33', 1, 'AB-111-CD');

-- --------------------------------------------------------

--
-- Structure de la table `proprietaires`
--

CREATE TABLE `proprietaires` (
  `id_proprietaire` int(11) NOT NULL,
  `id_vehicule` int(30) NOT NULL,
  `nom` varchar(30) NOT NULL,
  `prenom` varchar(30) NOT NULL,
  `email` text NOT NULL,
  `login` varchar(30) NOT NULL,
  `password` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `proprietaires`
--

INSERT INTO `proprietaires` (`id_proprietaire`, `id_vehicule`, `nom`, `prenom`, `email`, `login`, `password`) VALUES
(1, 1, 'boulanger', 'olivier', 'olivier@gmail.com', 'olivier', 'mdp'),
(2, 2, 'billard', 'sabrina', 'sabrina@gmail.com', 'sabrina', 'mdp'),
(3, 3, 'dachy', 'xavier', 'xavier@gmail.com', 'xavier', 'mdp'),
(4, 4, 'piat', 'solene', 'solene@gmail.com', 'solene', 'mdp'),
(5, 5, 'Foucaux', 'Jean-Pierre', 'jpfoucaux@gmail.com', 'jpfoucaux', 'mdp');

-- --------------------------------------------------------

--
-- Structure de la table `validateur`
--

CREATE TABLE `validateur` (
  `id_validateur` int(11) NOT NULL,
  `password` text NOT NULL,
  `login` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `validateur`
--

INSERT INTO `validateur` (`id_validateur`, `password`, `login`) VALUES
(1, 'validateur', 'validateur'),
(2, 'mdp', 'olivier'),
(16, 'a', 'a'),
(19, 'mdp', 'validateur1'),
(27, 'test', 'test'),
(30, 'mdp', 'Bertrand'),
(38, 'test', 'test'),
(39, 'mdp', 'JPGREMONT');

-- --------------------------------------------------------

--
-- Structure de la table `vehicules`
--

CREATE TABLE `vehicules` (
  `id_vehicule` int(11) NOT NULL,
  `id_proprietaire` int(10) NOT NULL,
  `immatriculation` varchar(12) NOT NULL,
  `carte_grise` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Contenu de la table `vehicules`
--

INSERT INTO `vehicules` (`id_vehicule`, `id_proprietaire`, `immatriculation`, `carte_grise`) VALUES
(1, 0, 'AB-111-CD', 'lien image ici 1'),
(2, 1, 'EF-222-GH', 'lien image ici 2'),
(3, 2, 'IJ-333-KL', 'lien image ici 3'),
(4, 3, 'MN-444-OP', 'lien image ici 4'),
(5, 4, 'QR-555-ST', 'lien image 5');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `demande`
--
ALTER TABLE `demande`
  ADD PRIMARY KEY (`id_demande`);

--
-- Index pour la table `message-validateur`
--
ALTER TABLE `message-validateur`
  ADD PRIMARY KEY (`id_message`);

--
-- Index pour la table `passages`
--
ALTER TABLE `passages`
  ADD PRIMARY KEY (`id_passage`),
  ADD KEY `id_vehicule` (`id_vehicule`);

--
-- Index pour la table `proprietaires`
--
ALTER TABLE `proprietaires`
  ADD PRIMARY KEY (`id_proprietaire`),
  ADD UNIQUE KEY `id_vehicule` (`id_vehicule`);

--
-- Index pour la table `validateur`
--
ALTER TABLE `validateur`
  ADD PRIMARY KEY (`id_validateur`);

--
-- Index pour la table `vehicules`
--
ALTER TABLE `vehicules`
  ADD PRIMARY KEY (`id_vehicule`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `demande`
--
ALTER TABLE `demande`
  MODIFY `id_demande` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;
--
-- AUTO_INCREMENT pour la table `message-validateur`
--
ALTER TABLE `message-validateur`
  MODIFY `id_message` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=35;
--
-- AUTO_INCREMENT pour la table `passages`
--
ALTER TABLE `passages`
  MODIFY `id_passage` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
--
-- AUTO_INCREMENT pour la table `proprietaires`
--
ALTER TABLE `proprietaires`
  MODIFY `id_proprietaire` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT pour la table `validateur`
--
ALTER TABLE `validateur`
  MODIFY `id_validateur` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=40;
--
-- AUTO_INCREMENT pour la table `vehicules`
--
ALTER TABLE `vehicules`
  MODIFY `id_vehicule` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
