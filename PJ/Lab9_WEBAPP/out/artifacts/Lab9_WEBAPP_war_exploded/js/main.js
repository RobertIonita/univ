// Wait for the DOM to be loaded
document.addEventListener('DOMContentLoaded', function () {
    let datePickers = document.querySelectorAll('.datepicker'),
        datePickerOptions = {
            "maxDate": new Date(),
            "yearRange" : 100,
            "firstDay": 1
        };
    M.Datepicker.init(datePickers, datePickerOptions);
});

