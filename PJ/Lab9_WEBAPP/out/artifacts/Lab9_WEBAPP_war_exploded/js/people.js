document.addEventListener('DOMContentLoaded', function () {
    const table = document.querySelector(".table_body"),
        populate = (people) => {
            console.log(people);
            people.forEach(person => {
                table.innerHTML +=
                    `<div class="row_body d_fl j_sb a_c">
                        <div class="column_body last_name"><span>${person.last_name}</span></div>
                        <div class="column_body first_name"><span>${person.first_name}</span></div>
                        <div class="column_body birth_date"><span>${person.birth_date}</span></div>
                        <div class="column_body address"><span>${person.address}</span></div>
                        <div class="column_body phone"><span>${person.phone}</span></div>
                    </div>`
            });
        };
    fetch("./people")
        .then(response => {
            response.json()
                .then(data => {
                    console.log(data);
                    populate(data);
                })
                .catch(error => console.error('Failed to parse json: ', error))
        })
        .catch(error => {
            console.error(error);
        });

    let datePickers = document.querySelectorAll('.datepicker'),
        datePickerOptions = {
            "maxDate": new Date()
        },
        selects = document.querySelectorAll('select');
    M.FormSelect.init(selects);
    M.Datepicker.init(datePickers, datePickerOptions);
});