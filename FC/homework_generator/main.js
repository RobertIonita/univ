window.onload = function () {

    var list = qA(".students ul li"),
        items = q(".items"),
        i = 0,
        ol;
    list.forEach(element => {
        items.innerHTML += `
            <div class="item">
                <p>Nume și Prenume: <b>${element.innerHTML}</b></p>
                <p>Efectuați adunarea în SM, C1 și C2 a numerelor ce urmează:</p>
                <ol type="a">
                </ol >
            </div >
        `
        ol = q("ol", qA(".item")[i]);
        var arr1 = [],
            arr2 = [],
            populate = (array) => {
                while (array.length < 10) {
                    var r = Math.floor(Math.random() * 9) + 1;
                    r = Math.floor(Math.random() * 2) ? "+"+r : "-"+r;
                    array.push(r);
                }
            };
        populate(arr1);
        populate(arr2);
        for (let j = 0; j < 10; j++) {
            ol.innerHTML += `<li>${arr1[j]} + ${arr2[j]}</li>`
        }
        i++;
    });
}