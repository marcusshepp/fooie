import { Injectable } from '@angular/core';
import { Hero } from './hero';
import { HEROES } from './mock-heroes';
import { Observable, of } from 'rxjs';
import { MessageService } from './message.service';
import { HttpClient, HttpHeaders  } from '@angular/common/http';
import { catchError, map, tap } from 'rxjs/operators';

@Injectable({
  providedIn: 'root'
})
export class HeroService {

  private heroesUrl = 'api/heroes';
  private httpPutOptions = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  };


  constructor(
    private messageService: MessageService,
    private http: HttpClient
  ) { }

  getHeroes(): Observable<Hero[]> {
    this.messageService.add('HeroService: fetched heroes');
    return this.http.get<Hero[]>(this.heroesUrl)
      .pipe(
        tap(_ => this.log('fetched heroes')),
        catchError(this.handleError('getHeroes', []))
      );
  }

  getHero(id: number): Observable<Hero> {
    this.messageService.add(`heroService: fetched hero id=${id}`);
    const url = `${this.heroesUrl}/${id}`;
    return this.http.get<Hero>(url).pipe(
      tap(_ => this.log(`fetched hero id = ${id}`)),
      catchError(this.handleError<Hero>(`getHero id = ${id}`))
    );
  }

  private log(message: string): void {
    this.messageService.add(`HeroService: $(message)`);
  }

  private handleError<T> (operation = 'operation', result?: T) {
    return (error: any): Observable<T> => {
      console.log(error);
      this.log(`${operation} failed: ${error.message}`);
      return of(result as T)
    }
  }

  updateHero(hero: Hero): Observable<any> {
    return this.http.put(this.heroesUrl, hero, this.httpPutOptions).pipe(
      tap(_ => this.log(`updated hero id=${hero.id}`)),
      catchError(this.handleError<any>('updateHero'))
    );
  }

  addHero(hero: Hero): Observable<Hero> {
    return this.http.post<Hero>(this.heroesUrl, hero, this.httpPutOptions).pipe(
      tap((newHero: Hero) => this.log(`added hero w/ id=${newHero.id}`)),
      catchError(this.handleError<Hero>('addHero'))
    );
  }

  deleteHero(hero: Hero | number): Observable<Hero> {
    const id = typeof hero === 'number' ? hero : hero.id;
    const url = `${this.heroesUrl}/${id}`;
    return this.http.delete<Hero>(url, this.httpPutOptions).pipe(
      tap(_ => this.log(`deleted hero id=${id}`)),
      catchError(this.handleError<Hero>('deleteHero'))
    );
  }

  searchHeroes(term: string): Observable<Hero[]> {
    if(!term.trim()) {
      // if not search term, return empty hero array
      return of([]);
    }
    return this.http.get<Hero[]>(`${this.heroesUrl}/?name=${term}`).pipe(
      tap(_ => this.log(`found heroes matching term '${term}'`)),
      catchError(this.handleError<Hero[]>('searchHeroes', []))
    );
  }
}
