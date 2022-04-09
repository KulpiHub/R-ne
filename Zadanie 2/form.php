<?php
    echo "Marka:"." ".$_POST["marka"]."<br />";
    echo "Model:"." ".$_POST["modell"]."<br />";
    echo "Rok:"." ".$_POST["rok"]."<br />";
    if(isset($_POST["paliwo"])){
        echo "Silnik:"." ".$_POST["paliwo"]."<br />";}
    echo "Kolor:"." ".$_POST["kolor"]."<br />";
    if(isset($_POS["nadwozie"])){
        echo "Typ Nadwozia"." ".$_POST["nadwozie"]."<br />";
    }
    $wyp = $_POST["wyp"];
        if (empty($wyp)){
            echo("Wyposażenie: Brak Wyposażenia")."<br />";
             }
        else {
            echo("Wyposażenie: ");
            for($i=0; $i < count($wyp); $i++) {
                $wyp2 = $wyp[$i].", ";
                echo($wyp2);
             }
            }
    echo "<br/>"."Stan ogólny:"." ".$_POST["stan"]."<br />";
    echo "Opis:"." ".$_POST["uwagi"]."<br />";
?>