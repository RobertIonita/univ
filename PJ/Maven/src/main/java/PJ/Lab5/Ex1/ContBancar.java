package PJ.Lab5.Ex1;
import java.util.Calendar;

public class ContBancar implements Operatiuni {

	private String numarCont;
	private float suma;
	private String moneda;
	private Calendar data_deschiderii;
	private Calendar data_ultimei_operatiuni;

	public ContBancar(String numarCont, float suma, String moneda, Calendar data_deschiderii,
			Calendar data_ultimei_operatiuni) {
		this.numarCont = numarCont;
		this.suma = suma;
		this.moneda = moneda;
		this.data_deschiderii = data_deschiderii;
		this.data_ultimei_operatiuni = data_ultimei_operatiuni;
	}

	public String getNumarCont() {
		return numarCont;
	}

	public void setNumarCont(String numarCont) {
		this.numarCont = numarCont;
	}

	public float getSuma() {
		return suma;
	}

	public void setSuma(float suma) {
		this.suma = suma;
	}

	public String getMoneda() {
		return moneda;
	}

	public void setMoneda(String moneda) {
		this.moneda = moneda;
	}

	public Calendar getData_deschiderii() {
		return data_deschiderii;
	}

	public void setData_deschiderii(Calendar data_deschiderii) {
		this.data_deschiderii = data_deschiderii;
	}

	public Calendar getData_ultimei_operatiuni() {
		return data_ultimei_operatiuni;
	}

	public void setData_ultimei_operatiuni(Calendar data_ultimei_operatiuni) {
		this.data_ultimei_operatiuni = data_ultimei_operatiuni;
	}

	public float calculeaza_dobanda() {
		float dobanda = 0;
		Calendar dataCurenta = Calendar.getInstance();
		long dataCrtMs = dataCurenta.getTimeInMillis();
		long dataLastMs = data_ultimei_operatiuni.getTimeInMillis();
		long ms = dataCrtMs - dataLastMs;
		long nrZile = ms / 86400000;
		if (moneda.toLowerCase() == "eur") {
			dobanda = (float) (0.1 * suma * nrZile);
		} else if (moneda.toLowerCase() == "ron") {
			if (suma < 500)
				dobanda = (float) (0.3 * suma * nrZile);
			else
				dobanda = (float) (0.8 * suma * nrZile);
		}

		data_ultimei_operatiuni = Calendar.getInstance();
		return dobanda;
	}

	public float actualizeaza_suma() {
		data_ultimei_operatiuni = Calendar.getInstance();
		return (suma + calculeaza_dobanda());
	}

	public void depunere(float suma) {
		this.suma = actualizeaza_suma() + suma;
		data_ultimei_operatiuni = Calendar.getInstance();
	}

	public void extragere(float suma) {
		this.suma = actualizeaza_suma() - suma;
		data_ultimei_operatiuni = Calendar.getInstance();
	}

	public String toString() {
		return numarCont + " " + String.valueOf(suma) + " " + moneda + " " + String.valueOf(data_deschiderii) + " "
				+ String.valueOf(data_ultimei_operatiuni);
	}
}
