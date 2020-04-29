package PJ.Lab5.Ex1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class ClientiiBancilor {

	public static void main(String[] args) throws IOException, Client {
		Meniu();
	}

	public static void Meniu() throws IOException, Client {

		BufferedReader flux_in = new BufferedReader(new InputStreamReader(System.in));

		List<Banca> banci = new ArrayList<Banca>();

		String linieOp;
		String linieBanca;
		String linieNrClienti;
		String linieAdresaClient;
		String linieClienti;
		String linieNrConturi;
		String linieNrCont;
		String linieSuma;
		String linieMoneda;

		Calendar dataDeschiderii;
		Calendar dataUltimeiOperatiuni;

		int op;

		do {
			System.out.println();
			System.out.println("1.Adaugare banci, clienti, conturi");
			System.out.println("2.Afisarea date introduse");
			System.out.println("3.Depunere suma in cont");
			System.out.println("4.Extragere suma din cont");
			System.out.println("5.Transfer de bani intre doua conturi");
			System.out.println("0.Iesire");
			System.out.print("Introduceti optiunea: ");
			linieOp = flux_in.readLine();
			op = Integer.parseInt(linieOp);
			System.out.println();
			switch (op) {
				case 1:
					System.out.print("Introduceti nume banca: ");
					linieBanca = flux_in.readLine();
					System.out.print("Introduceti numar clienti: ");
					linieNrClienti = flux_in.readLine();
					int contorClienti = 0;

					List<Client> clienti = new ArrayList<Client>();

					while (contorClienti < Integer.parseInt(linieNrClienti)) {
						System.out.print("Introduceti numele clientului: ");
						linieClienti = flux_in.readLine();

						System.out.print("Introduceti adresa clientului: ");
						linieAdresaClient = flux_in.readLine();

						System.out.print("Introduceti numarul de conturi pentru acest client: ");
						linieNrConturi = flux_in.readLine();

						int contorConturi = 0;
						List<ContBancar> conturi = new ArrayList<ContBancar>();

						while (contorConturi < Integer.parseInt(linieNrConturi)) {
							System.out.print("Introduceti numar cont: ");
							linieNrCont = flux_in.readLine();

							System.out.print("Introduceti suma in cont: ");
							linieSuma = flux_in.readLine();

							System.out.print("Introduceti moneda contului: ");
							linieMoneda = flux_in.readLine();

							dataDeschiderii = Calendar.getInstance();
							dataUltimeiOperatiuni = Calendar.getInstance();

							ContBancar cont = new ContBancar(linieNrCont, Float.parseFloat(linieSuma), linieMoneda,
									dataDeschiderii, dataUltimeiOperatiuni);
							conturi.add(cont);

							contorConturi++;

						}

						Client client = new Client(linieClienti, linieAdresaClient, conturi);
						clienti.add(client);
						contorClienti++;

					}

					Banca banca = new Banca(linieBanca, clienti);
					banci.add(banca);

					break;

				case 2:
					for (int i = 0; i < banci.size(); i++) {
						System.out.println("Nume banca: " + banci.get(i).getDenumire_banca());
						for (int j = 0; j < banci.get(i).getClienti().size(); j++) {
							System.out.print("Nume client: " + banci.get(i).getClienti().get(j).getNume() + " ");
							System.out.println("Adresa client: " + banci.get(i).getClienti().get(j).getAdresa());
							for (int k = 0; k < banci.get(i).getClienti().get(j).getConturi().size(); k++) {
								System.out.print("Numar cont: "
										+ banci.get(i).getClienti().get(j).getConturi().get(k).getNumarCont());
								System.out.print(
										" Suma: " + banci.get(i).getClienti().get(j).getConturi().get(k).getSuma());
								System.out.print(
										" Moneda: " + banci.get(i).getClienti().get(j).getConturi().get(k).getMoneda());
								System.out.print(" Dobanda: "
										+ banci.get(i).getClienti().get(j).getConturi().get(k).calculeaza_dobanda());
								System.out.println();

							}
							System.out.println();

						}
						System.out.println();
					}

					break;

				case 3:
					System.out.print("Introduceti numar cont: ");
					linieNrCont = flux_in.readLine();
					boolean gasit = false;
					for (int i = 0; i < banci.size(); i++) {
						for (int j = 0; j < banci.get(i).getClienti().size(); j++) {
							for (int k = 0; k < banci.get(i).getClienti().get(j).getConturi().size(); k++) {
								if (banci.get(i).getClienti().get(j).getConturi().get(k).getNumarCont().toLowerCase()
										.equalsIgnoreCase(linieNrCont)) {
									gasit = true;
									System.out.print("Introduceti suma: ");
									linieSuma = flux_in.readLine();
									banci.get(i).getClienti().get(j).getConturi().get(k)
											.depunere(Float.parseFloat(linieSuma));
									break;
								}

							}

						}
					}

					if (gasit == false)
						System.out.println("Nu exista astfel de cont!");

					System.out.println();
					break;

				case 4:
					System.out.print("Introduceti numar cont: ");
					linieNrCont = flux_in.readLine();
					boolean found = false;
					for (int i = 0; i < banci.size(); i++) {
						for (int j = 0; j < banci.get(i).getClienti().size(); j++) {
							for (int k = 0; k < banci.get(i).getClienti().get(j).getConturi().size(); k++) {
								if (banci.get(i).getClienti().get(j).getConturi().get(k).getNumarCont().toLowerCase()
										.equalsIgnoreCase(linieNrCont)) {
									found = true;
									System.out.print("Introduceti suma: ");
									linieSuma = flux_in.readLine();

									if (Float.parseFloat(linieSuma) > banci.get(i).getClienti().get(j).getConturi()
											.get(k).getSuma())
										System.out.println("Nu ai atatia bani in cont!");
									else
										banci.get(i).getClienti().get(j).getConturi().get(k)
												.extragere(Float.parseFloat(linieSuma));
									break;
								}

							}

						}
					}

					if (found == false)
						System.out.println("Nu exista astfel de cont!");

					System.out.println();
					break;

				case 5:
					System.out.print("Introduceti numar cont de unde vreti sa luati: ");
					linieNrCont = flux_in.readLine();

					float contTemp = 0;
					boolean gasit2 = false;
					int vec[] = new int[3];

					for (int i = 0; i < banci.size(); i++) {
						for (int j = 0; j < banci.get(i).getClienti().size(); j++) {
							for (int k = 0; k < banci.get(i).getClienti().get(j).getConturi().size(); k++) {
								if (banci.get(i).getClienti().get(j).getConturi().get(k).getNumarCont().toLowerCase()
										.equalsIgnoreCase(linieNrCont)) {
									gasit2 = true;
									contTemp = banci.get(i).getClienti().get(j).getConturi().get(k).getSuma();
									vec[0] = i;
									vec[1] = j;
									vec[2] = k;
									break;
								}

							}

						}
					}

					if (gasit2 == false) {
						System.out.println("Nu exista astfel de cont!");
						break;
					}

					System.out.print("Introduceti numar cont unde vreti sa adaugati: ");
					String linieNrCont2 = flux_in.readLine();

					gasit2 = false;
					for (int i = 0; i < banci.size(); i++) {
						for (int j = 0; j < banci.get(i).getClienti().size(); j++) {
							for (int k = 0; k < banci.get(i).getClienti().get(j).getConturi().size(); k++) {
								if (banci.get(i).getClienti().get(j).getConturi().get(k).getNumarCont().toLowerCase()
										.equalsIgnoreCase(linieNrCont2)) {
									gasit2 = true;

									System.out.print("Introduceti suma: ");
									linieSuma = flux_in.readLine();

									if (Float.parseFloat(linieSuma) > contTemp)
										System.out.println("Contul donator nu detine asemenea suma!");
									else {
										banci.get(i).getClienti().get(j).getConturi().get(k)
												.depunere(Float.parseFloat(linieSuma));
										banci.get(vec[0]).getClienti().get(vec[1]).getConturi().get(vec[2])
												.extragere(Float.parseFloat(linieSuma));
									}
									break;
								}

							}

						}
					}

					if (gasit2 == false) {
						System.out.println("Nu exista astfel de cont!");
					}

					System.out.println();
					break;

				case 0:
					break;

				default:
					System.out.println("Optiunea nu se gaseste in lista");
					System.out.println();
			}

		} while (op != 0);

	}
}
