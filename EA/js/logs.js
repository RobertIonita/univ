var makeLog, likeLog, deleteLog, deleteLog, setFilter,
    nearest = (name, node) => {
        while (node.className.indexOf(name) == -1 && parent != null)
            node = node.parentElement;
        return node;
    }

document.addEventListener('DOMContentLoaded', function () {
    const form = document.querySelector("form"),
        logs_container = document.getElementById("logs"),
        api = "http://" + window.location.hostname + ":3000";
    async function getRecordsAsync(url) {
        let response = await fetch(url),
            data = await response.json()
        return data;
    }
    getRecordsAsync(api + '/temperature?_sort=time&_order=desc&_page=1&_limit=10')
        .then(data => {
            renderLogs(data)
            // var req = new XMLHttpRequest();
            // req.open('GET', api + '/light?_sort=time&_order=desc&_page=1&_limit=10', false);
            // req.send(null);
            // var headers = req.getAllResponseHeaders();
        })
    fetch(api + '/light?_sort=time&_order=desc&_page=1&_limit=10')
        .then((response) => {
            return response.json();
        })
        .then((myJson) => {
            // console.log(myJson);
        });
    var renderLogs = (records) => {
        logs_container.innerHTML = `
            <table class="striped centered">
                <thead>
                    <tr>
                        <th>Date</th>
                        <th>Time</th>
                        <th>Value</th>
                        <th>Set</th>
                        <th width="60">Action</th>
                    </tr>
                </thead>
                <tbody>`;
        records.forEach(element => {
            logs_container.querySelector('tbody').innerHTML += `
                    <tr class="log">
                        <td>${element.date}</td>
                        <td>${element.time}</td>
                        <td>${element.value}</td>
                        <td>${element.set}</td>
                        <td><i class="material-icons clickable" onclick="deleteLog('${element.id}')">delete</i><td>
                    </tr>`
        });
    }
    deleteLog = (id) => {
        fetch(api + '/' + getActiveTab() + '/' + id, { method: 'DELETE' })
        logs_container.querySelector('tbody').removeChild(nearest("log", event.target));
    }
    setFilter = () => {
        let date = this.querySelector(".datepicker").value,
            time = this.querySelector(".timepicker").value;
        if (date != "" && time != "") {
            updateLogs(getActiveTab().toLowerCase(), date, time + ":00")
        }
        else {
            M.toast({ html: 'Please select date and time' })
        }
    }
    var getActiveTab = () => {
        var tab = document.querySelector('.tabs .active');
        return tab.innerHTML;
    },
        updateLogs = (type, date, time) => {
            let location = api + `/${type}?q=${date}&time_gte=${time}&_sort=time&_order=desc&_page=1&_limit=10`;
            getRecordsAsync(location)
                .then(data => {
                    renderLogs(data)
                    console.log(type, data, logs_container, location)
                })
        }
    navElems = document.querySelectorAll('.sidenav'),
        tabElems = document.querySelectorAll('.tabs'),
        navOptions = {
            "edge": "right"
        },
        tabOptions = {
            "onShow": function () {
                var link = api + this.$activeTabLink[0].hash.replace('#', '/');
                getRecordsAsync(link + "?_sort=time&_order=desc&_page=1&_limit=10")
                    .then(data => renderLogs(data));
            }
        },
        datepicker = document.querySelectorAll('.datepicker'),
        timepicker = document.querySelectorAll('.timepicker'),
        currentDate = new Date(),
        dateOptions = {
            "maxDate": currentDate
        }
    timeOptions = {
        "twelveHour": false
    }

    M.Sidenav.init(navElems, navOptions);
    M.Datepicker.init(datepicker, dateOptions);
    M.Timepicker.init(timepicker, timeOptions);
    M.Tabs.init(tabElems, tabOptions);
});