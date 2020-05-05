<%--
  Created by IntelliJ IDEA.
  User: alexandru
  Date: 05/05/2020
  Time: 01:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <link rel="stylesheet" href="css/people.css"/>
    <link rel="icon-x/image" href="assets/favicon.ico"/>
    <title>JSP WEB Application | People</title>
</head>
<body>
<h4>Persoanele introduse</h4>
<div class="main_container">
    <div class="table card">
        <div class="controls d_fl j_sb">
            <div class="input-field date_from">
                <input id="birth_date" name="birth_date" type="text" class="datepicker">
                <label for="birth_date">Începând de la:</label>
            </div>
            <i class="material-icons download">get_app</i>
        </div>
        <div class="table_heading">
            <div class="row_body d_fl j_sb a_c">
                <div class="column_body last_name"><span>Nume</span></div>
                <div class="column_body first_name"><span>Prenume</span></div>
                <div class="column_body birth_date"><span>Data nașterii</span></div>
                <div class="column_body address"><span>Adresa</span></div>
                <div class="column_body phone"><span>Nr telefon</span></div>
            </div>
        </div>
        <div class="table_body">
        </div>
        <div class="go_back">
            <a href="./" class="btn">Go back</a>
        </div>
    </div>
</div>
<script src="js/FileSaver.min.js"></script>
<script src="js/xlsx.full.min.js"></script>
<script src="js/people.js"></script>
<script src="js/materialize.min.js"></script>
</body>
</html>
