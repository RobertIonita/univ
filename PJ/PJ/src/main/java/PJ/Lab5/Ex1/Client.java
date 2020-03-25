package PJ.Lab5.Ex1;

import java.util.List;

public class Client extends Exception {
	/**
	 *
	 */
	private static final long serialVersionUID = 1L;
	private String nume;
	private String adresa;
	private List<ContBancar> conturi;

	private boolean errorMessage;

	public Client(String nume, String adresa, List<ContBancar> conturi) throws Client {
		if (conturi.size() >= 1 && conturi.size() <= 5) {
			this.nume = nume;
			this.adresa = adresa;
			this.conturi = conturi;
		} else {
			errorMessage = true;
			throw this;
		}
	}

	public String getNume() {
		return nume;
	}

	public void setNume(String nume) {
		this.nume = nume;
	}

	public String getAdresa() {
		return adresa;
	}

	public void setAdresa(String adresa) {
		this.adresa = adresa;
	}

	public List<ContBancar> getConturi() {
		return conturi;
	}

	public void setConturi(List<ContBancar> conturi) {
		this.conturi = conturi;
	}

	public String toString(int counter) {
		if (errorMessage)
			return "Un client trebuie să aibă cel putin un cont, dar nu mai mult de cinci conturi";
		else {
			return super.toString() + " " + nume + " " + adresa + " " + conturi.get(counter).getNumarCont()
					+ conturi.get(counter).getSuma() + conturi.get(counter).getMoneda()
					+ conturi.get(counter).getData_deschiderii() + conturi.get(counter).getData_ultimei_operatiuni();
		}
	}
}
