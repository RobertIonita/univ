window.onload = function() {

    var list = qA(".students ul li"),
        student = {
            name: this.undefined
        }
    list.forEach(element => {
        this.console.log(element.innerHTML);
    });
}