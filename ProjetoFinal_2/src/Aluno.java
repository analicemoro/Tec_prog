public class Aluno {
    // atributos
    private String nome;
    private int faltas;
    private double nota1;
    private double nota2;

    //métodos

    public Aluno(String nome, int faltas, double nota1, double nota2) {
        this.nome = nome;
        this.faltas = faltas;
        this.nota1 = nota1;
        this.nota2 = nota2;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getFaltas() {
        return faltas;
    }

    public void setFaltas(int faltas) {
        this.faltas = faltas;
    }

    public double getNota1() {
        return nota1;
    }

    public void setNota1(double nota1) {
        this.nota1 = nota1;
    }

    public double getNota2() {
        return nota2;
    }

    public void setNota2(double nota2) {
        this.nota2 = nota2;
    }

    public double calcularMedia(){
        return ((nota1 + nota2) / 2);
    }

    public double calcularFrequencia(){
        return (((double) (70 - faltas) / 70) * 100);
    }

    public String status(){
        if(calcularMedia() > 6.0 && calcularFrequencia() > 75){
            return ("Aprovado");
        } else if (calcularMedia() > 6.0 && calcularFrequencia() < 75){
            return ("Reprovado por frequência");
        } else if (calcularMedia() < 6.0 && calcularFrequencia() > 75){
            return ("Reprovado por nota");
        } else return ("Reprovado por nota e frequência");
    }

    @Override
    public String toString() {
        String result;
        result = String.format( "Nome: %s" +
                "\nFaltas: %d (%.2f%% de freq.)" +
                "\nNotas: %.2f; %.2f" +
                "\nMédia: %.2f" +
                "\nStatus: %s",
                nome, faltas, calcularFrequencia(), nota1, nota2, calcularMedia(), status());

        return (result);
    }
}
