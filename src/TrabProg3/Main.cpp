package TrabProg3;

import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Main {

	public static void main(String[] args) throws IOException, ParseException {

		Eleicao vereador = new Eleicao(); 
		String arquivoCandidatos = args[0];
		String arquivoPartidos = args[1];		
		String dataString = args[2];
		Leitura lerPartidos = new Leitura(); 
		lerPartidos.lePartidos(vereador,arquivoPartidos);
		Leitura lerCandidatos = new Leitura(); 
		lerCandidatos.leCandidatos(vereador,arquivoCandidatos);
		Escrita escreveArquivoSaida = new Escrita();
		SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
        Date data = formato.parse(dataString);
		escreveArquivoSaida.escreveArquivo("out.txt",data,vereador);		
	}
}


