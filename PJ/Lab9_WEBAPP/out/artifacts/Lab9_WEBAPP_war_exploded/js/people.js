document.addEventListener('DOMContentLoaded', function () {
    const table = document.querySelector(".table_body"),
        appendPerson = (person) => {
            table.innerHTML +=
                `<div class="row_body d_fl j_sb a_c">
                    <div class="column_body last_name"><span>${person.last_name}</span></div>
                    <div class="column_body first_name"><span>${person.first_name}</span></div>
                    <div class="column_body birth_date"><span>${person.birth_date}</span></div>
                    <div class="column_body address"><span>${person.address}</span></div>
                    <div class="column_body phone"><span>${person.phone}</span></div>
                </div>`
        }
        populate = (people) => {
            people.forEach(person => {
                appendPerson(person);
            });
        };
    var people = [];
    fetch("./people")
        .then(response => {
            response.json()
                .then(data => {
                    people = data;
                    populate(data);
                })
                .catch(error => console.error('Failed to parse json: ', error))
        })
        .catch(error => {
            console.error(error);
        });
    const filterDate = (filter_date) => {
            table.innerHTML = "";
            people.forEach(person => {
               if(Date.parse(person.birth_date) >= filter_date)
                   appendPerson(person);
            });
        },
        datePickers = document.querySelectorAll('.datepicker'),
        datePickerOptions = {
            "maxDate": new Date(),
            "firstDay": 1,
            "onClose": function() {
                filterDate(this.date)
            }
        },
        selects = document.querySelectorAll('select');
    M.FormSelect.init(selects);
    M.Datepicker.init(datePickers, datePickerOptions);
});