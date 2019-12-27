var makeLog, likeLog, deleteLog, deleteLog;
var nearest = (name, node) => {
    while (node.className.indexOf(name) == -1 && parent != null)
        node = node.parentElement;
    return node;
}

document.addEventListener('DOMContentLoaded', function () {
    const form = document.querySelector("form"),
        logs_container = document.getElementById("logs"),
        api = "http://"+window.location.hostname + ":3000";
    console.log(api)
    async function getRecordsAsync(url) {
        let response = await fetch(url),
            data = await response.json()
        return data;
    }
    getRecordsAsync(api + '/light')
        .then(data => renderLogs(data));
    var renderLogs = (records) => {
        logs_container.innerHTML = `
            <table class="striped centered">
                <thead>
                    <tr>
                        <th>Time</th>
                        <th>Value</th>
                        <th>Set</th>
                        <th width="60">Action</th>
                    </tr>
                </thead>
                <tbody>`;
        records.sort((a, b) => (a.Likes < b.Likes) ? 1 : -1);
        records.forEach(element => {
            logs_container.querySelector('tbody').innerHTML += `
                    <tr class="log">
                        <td>${element.time}</td>
                        <td>${element.value}</td>
                        <td>${element.set}</td>
                        <td><i class="material-icons clickable" onclick="deleteLog('${element.id}')">delete</i><td>
                    </tr>`
        });
    }
    var getActiveTab = () => {
        var tab = document.querySelector('.tabs .active');
        return tab.innerHTML;
    }
    likeLog = function (id) {
        fetch(url + '/like/' + id, { method: 'PUT' })
        let counter = nearest("actions_aria", event.target).querySelector("span");
        counter.innerHTML = Number(counter.innerHTML) + 1;
    }
    dislikeLog = (id) => {
        fetch(url + '/dislike/' + id, { method: 'PUT' })
        let counter = nearest("actions_aria", event.target).querySelector("span");
        counter.innerHTML == "0" ? 0 : counter.innerHTML = Number(counter.innerHTML) - 1;
    }
    deleteLog = (id) => {

        fetch(api + '/' + getActiveTab() + '/' + id, { method: 'DELETE' })
        logs_container.querySelector('tbody').removeChild(nearest("log", event.target));

    }

    var navElems = document.querySelectorAll('.sidenav'),
        tabElems = document.querySelectorAll('.tabs'),
        navOptions = {
            "edge": "right"
        },
        tabOptions = {
            "onShow": function () {
                var link = api + this.$activeTabLink[0].hash.replace('#', '/');
                getRecordsAsync(link)
                    .then(data => renderLogs(data));
            }
        },
        sidenav = M.Sidenav.init(navElems, navOptions),
        tabs = M.Tabs.init(tabElems, tabOptions);
});