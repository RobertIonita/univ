<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <link rel="stylesheet" href="css/add.css"/>
    <link rel="icon-x/image" href="assets/favicon.ico"/>
    <title>JSP WEB Application | Form</title>
</head>
<body>
<div class="main_container">
    <h4>Adăugare informații</h4>
    <div class="card">
        <form method="post" action="./people">
            <h5>Toate câmpurile sunt obligatorii</h5>
            <div id="data_form" method="post">
                <div class="d_fl a_c j_sb">
                    <div class="input-field">
                        <input id="last_name" pattern="^[a-zA-ZșțȘȚâîÎ ]{2,30}$" class="validate"
                               type="text" name="last_name" required>
                        <label for="last_name">Nume</label>
                    </div>
                    <div class="input-field">
                        <input id="first_name" pattern="^[a-zA-ZșțȘȚâîÎ ]{2,30}$" class="validate"
                               type="text" name="first_name" required>
                        <label for="first_name">Prenume</label>
                    </div>
                </div>
                <div class="d_fl a_c j_sb">
                    <div class="input-field">
                        <input id="birth_date" name="birth_date" type="text" class="datepicker validate" required>
                        <label for="birth_date">Data nașterii</label>
                    </div>
                    <div class="input-field">
                        <input id="phone_number" pattern="^[+]*[(]{0,1}[0-9]{1,4}[)]{0,1}[-\s\./0-9]*$"
                               class="validate" name="phone" type="tel">
                        <label for="phone_number">Telefon</label>
                    </div>
                </div>
                <div class="d_fl a_c j_sb">
                    <div class="input-field text_area">
                        <label for="address">Adresa</label>
                        <input id="address" name="address" type="text" class="validate"
                                  required pattern="^[^\x22'` ][^\x22'`]+[^\x22'` ]$"/>
                        <span class="helper-text"
                              data-error="Nu sunt permise caracterele „ ' ”, „ &#x22; ”, precum și spații la început și sfârșit"></span>
                    </div>
                </div>
                <input type="submit" class="btn" value="Adaugă"/>
        </form>
    </div>
</div>

<script type="text/javascript" src="js/materialize.min.js" defer></script>
<script type="text/javascript" src="js/add.min.js" defer></script>
</body>
</html>
