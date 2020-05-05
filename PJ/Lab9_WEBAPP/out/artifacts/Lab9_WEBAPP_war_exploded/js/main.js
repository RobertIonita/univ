// Wait for the DOM to be loaded
document.addEventListener('DOMContentLoaded', function () {
    let datePickers = document.querySelectorAll('.datepicker'),
        datePickerOptions = {
            "maxDate": new Date()
        };
        M.Datepicker.init(datePickers, datePickerOptions);
});

