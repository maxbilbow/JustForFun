//
//  ViewController.swift
//  BoatGPS
//
//  Created by Max Bilbow on 21/06/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

import UIKit
//import MapKit
import CoreLocation

class ViewController: UIViewController, CLLocationManagerDelegate {
    
//    var mapView: MKMapView!
    var timer: NSTimer!
    var locationManager: CLLocationManager!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.

//        self.mapView = MKMapView(frame: self.view.bounds)
        self.locationManager = CLLocationManager.new()
        self.locationManager.delegate = self
        if CLLocationManager.locationServicesEnabled() {
            
            
//            self.locationManager.requestWhenInUseAuthorization()
            CLLocationManager.requestWhenInUseAuthorization(self.locationManager)()
            CLLocationManager.startUpdatingLocation(self.locationManager)()
//            self.locationManager.startUpdatingLocation()
            
            
            switch CLLocationManager.authorizationStatus() {
            case .NotDetermined:
                self.locationManager.requestAlwaysAuthorization()
            case .AuthorizedAlways, .AuthorizedWhenInUse, .Restricted, .Denied:
                let alertController = UIAlertController(
                    title: "Background Location Access Disabled",
                    message: "In order to be notified about adorable kittens near you, please open this app's settings and set location access to 'Always'.",
                    preferredStyle: .Alert)
                
                let cancelAction = UIAlertAction(title: "Cancel", style: .Cancel, handler: nil)
                alertController.addAction(cancelAction)
                
                let openAction = UIAlertAction(title: "Open Settings", style: .Default) { (action) in
                    if let url = NSURL(string:UIApplicationOpenSettingsURLString) {
                        UIApplication.sharedApplication().openURL(url)
                    }
                }
                alertController.addAction(openAction)
                
                self.presentViewController(alertController, animated: true, completion: nil)
            }
            print("location services are enabled")
        }
//        self.view.addSubview(self.mapView)
//        self.mapView.showsUserLocation = true
        
//        self.mapView.delegate = self
        self.timer = NSTimer.scheduledTimerWithTimeInterval(1, target: self, selector: "printLocation", userInfo: nil, repeats: true)
        
    }
    func locationManager(manager: CLLocationManager, didUpdateLocations locations: [AnyObject]) {
        print(__LINE__)
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    var first = true
    func locationManager(manager: CLLocationManager, didChangeAuthorizationStatus status: CLAuthorizationStatus) {
        if status == .AuthorizedAlways || status == .AuthorizedWhenInUse {
            manager.startUpdatingLocation()
        }
    
        
        
    }
    func locationManager(manager: CLLocationManager, didUpdateToLocation newLocation: CLLocation, fromLocation oldLocation: CLLocation) {
        print(__LINE__)
    }
    
    func printLocation(){
//        let location: MKUserLocation = self.mapView.userLocation
        //        self.locationManager.requestLocation()
        
//        if !location.updating {
//            print("Not updating")
//        } else {
//            print("\(location.coordinate.latitude) \(location.coordinate.longitude)")
//        }
        
            print("location \(self.locationManager.location): \(self.locationManager.description)")
    }
}

