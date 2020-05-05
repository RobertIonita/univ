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
    let people = [];
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
                if (Date.parse(person.birth_date) >= filter_date)
                    appendPerson(person);
            });
        },
        datePickers = document.querySelectorAll('.datepicker'),
        datePickerOptions = {
            "maxDate": new Date(),
            "yearRange": 100,
            "firstDay": 1,
            "onClose": function () {
                filterDate(this.date)
            }
        },
        btn_download = document.querySelector("i.download"),
        stringToArrayBuffer = (str) => {
            let buf = new ArrayBuffer(str.length),
                view = new Uint8Array(buf);
            for (let i = 0; i < str.length; i++)
                view[i] = str.charCodeAt(i) & 0xFF;
            return buf;
        };

    btn_download.onclick = () => {
        let report = XLSX.utils.book_new(),
            people_sheet = XLSX.utils.json_to_sheet(people);

        report.Props = {
            Title: "JSP Web Application",
            Subject: "Collected data",
            Author: "alexandru@tonu.rocks",
            CreatedDate: new Date()
        };
        report.SheetNames.push("People");
        report.Sheets["People"] = people_sheet;

        let wordbook = XLSX.write(report, {bookType: 'xlsx', type: 'binary'});
        saveAs(new Blob([stringToArrayBuffer(wordbook)], {type: "application/octet-stream"}), 'Report.xlsx');
    };
    M.Datepicker.init(datePickers, datePickerOptions);
});